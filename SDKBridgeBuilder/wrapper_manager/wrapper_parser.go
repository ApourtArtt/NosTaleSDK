package wrapper_manager

import (
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strings"
)

var (
	reName         *regexp.Regexp
	reIncludes     *regexp.Regexp
	reFunctionDefs *regexp.Regexp
	reVariableDefs *regexp.Regexp
	reClassBody    *regexp.Regexp
)

func init() {
	reName = regexp.MustCompile(`Wrapper\s*<\s*Entwell\s*::\s*DelphiClasses\s*::\s*([[:graph:]]+)\s*>`)
	reIncludes = regexp.MustCompile(`#include (["<].+[">])`)
	reFunctionDefs = regexp.MustCompile(`\s*[[:graph:]]*\s*[[:graph:]]*\s*\(.*\)`)
	reVariableDefs = regexp.MustCompile(`\s*[[:graph:]]+\s+[[:graph:]]+\s*[={;]`)
	reClassBody = regexp.MustCompile(`class\s+[[:graph:]]*.+\s*{\s*([\s\S]+)}\s*;`)
}

func GetWrappers(inputFolder string) ([]Wrapper, error) {
	dirs, err := os.ReadDir(inputFolder)
	if err != nil {
		return nil, err
	}

	var wrappers []Wrapper

	for i := 0; i < len(dirs); i++ {
		dir := dirs[i]
		if !dir.IsDir() {
			continue
		}

		err := filepath.Walk(inputFolder+dir.Name(), func(path string, info os.FileInfo, _ error) error {
			if info.IsDir() {
				return nil
			}

			fmt.Println("Parsing", path)

			data, err := os.ReadFile(path)
			if err != nil {
				return err
			}

			if strings.Contains(string(data), "SDKBridgeBuilder:IGNORE") {
				fmt.Println(info.Name(), "was skipped because it is marked as IGNORE")
				return nil
			}

			wrapper, err := parseWrapper(string(data))
			if err != nil {
				return err
			}

			wrappers = append(wrappers, wrapper)

			return nil
		})
		if err != nil {
			return nil, err
		}
	}

	return wrappers, nil
}

func parseWrapper(data string) (Wrapper, error) {
	includeMatches := reIncludes.FindAllStringSubmatch(data, -1)
	includes := make(map[string]struct{})
	for i := 0; i < len(includeMatches); i++ {
		if len(includeMatches) < 2 {
			return Wrapper{}, fmt.Errorf("include cannot be found: %v", includeMatches[i])
		}
		includes[includeMatches[i][1]] = struct{}{}
	}

	name := reName.FindAllStringSubmatch(data, -1)
	if len(name) == 0 || len(name[0]) < 2 {
		return Wrapper{}, fmt.Errorf("cannot find name: %v", name)
	}

	classBody := reClassBody.FindAllStringSubmatch(data, -1)
	if len(classBody) == 0 || len(classBody[0]) < 2 {
		return Wrapper{}, fmt.Errorf("class body cannot be found: %v", classBody)
	}

	wrapper, err := parseBody(classBody[0][1])
	if err != nil {
		return Wrapper{}, err
	}

	wrapper.Includes = includes
	wrapper.Name = name[0][1]

	return wrapper, nil
}

func parseBody(data string) (Wrapper, error) {
	private, public, protected := getBlocks(data)

	fmt.Println(private, public, protected)

	privateBlock, err := createClassBlock(private)
	if err != nil {
		return Wrapper{}, err
	}

	publicBlock, err := createClassBlock(public)
	if err != nil {
		return Wrapper{}, err
	}

	protectedBlock, err := createClassBlock(protected)
	if err != nil {
		return Wrapper{}, err
	}

	return Wrapper{
		PrivateBlock:   privateBlock,
		PublicBlock:    publicBlock,
		ProtectedBlock: protectedBlock,
	}, nil
}

func getBlocks(data string) (string, string, string) {
	currentVisibility := "private:"
	lines := strings.Split(data, "\n")
	blocks := map[string]string{
		"private:":   "",
		"public:":    "",
		"protected:": "",
	}

	for i := 0; i < len(lines); i++ {
		line := strings.TrimSpace(lines[i])
		if strings.HasSuffix(line, "private:") {
			currentVisibility = "private:"
		} else if strings.HasSuffix(line, "public:") {
			currentVisibility = "public:"
		} else if strings.HasSuffix(line, "protected:") {
			currentVisibility = "protected:"
		} else {
			blocks[currentVisibility] += line + "\n"
		}
	}

	return strings.TrimSpace(blocks["private:"]),
		strings.TrimSpace(blocks["public:"]),
		strings.TrimSpace(blocks["protected:"])
}

func createClassBlock(block string) (ClassBlock, error) {
	var functions []string
	for {
		begin, end := detectFunctionIndices(block)
		if begin == -1 || end == -1 {
			break
		}

		functions = append(functions, block[begin:end])
		block = block[0:begin] + block[end:]
	}

	var variables []string
	for {
		begin, end := detectVariableIndices(block)
		if begin == -1 || end == -1 {
			break
		}

		variables = append(variables, block[begin:end])
		block = block[0:begin] + block[end:]
	}

	return ClassBlock{
		Functions: strings.Join(functions, "\n"),
		Variables: strings.Join(variables, "\n"),
	}, nil
}

func detectFunctionIndices(block string) (int, int) {
	res := reFunctionDefs.FindStringSubmatchIndex(block)
	if len(res) < 2 {
		return -1, -1
	}

	begin := res[0]
	block = block[res[1]:]

	stack := ""

	for end, b := range block {
		c := byte(b)
		if c == '{' {
			stack += "{"
		} else if c == '}' {
			if len(stack) == 0 {
				return -1, -1
			}
			stack = stack[0 : len(stack)-1]
			if len(stack) == 0 {
				return begin, res[1] + end + 1
			}
		}
	}

	return -1, -1
}

func detectVariableIndices(block string) (int, int) {
	res := reVariableDefs.FindStringSubmatchIndex(block)
	if len(res) < 2 {
		return -1, -1
	}

	begin := res[0]
	block = block[begin:]

	stack := ""
	lastStackAdded := byte(0)
	for i := 0; i < len(block); i++ {
		c := byte(block[i])
		if c == ';' && len(stack) == 0 {
			return begin, i + 1
		}

		if lastStackAdded != '\'' && lastStackAdded != '"' {
			if c == '(' || c == '[' || c == '{' {
				stack += string(c)
				lastStackAdded = c
			} else if c == ')' || c == ']' || c == '}' {
				lastStackAdded = stack[len(stack)-1]
				stack = stack[0 : len(stack)-1]
			}
		}

		if c == '\'' || c == '"' {
			cString := string(c)
			idx := strings.LastIndex(stack, cString)
			if idx == -1 {
				stack += cString
				lastStackAdded = c
			} else {
				stack = stack[0:idx]
				lastStackAdded = 0
			}
		}
	}

	return -1, -1
}
