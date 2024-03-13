package class_manager

import (
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strings"
)

var (
	reClassName       *regexp.Regexp
	reClassParentName *regexp.Regexp
	reClassMemberLine *regexp.Regexp
	reClassSize       *regexp.Regexp
)

func init() {
	reClassName = regexp.MustCompile(`struct\s+([[:graph:]]+)`)
	reClassParentName = regexp.MustCompile(`struct\s+[[:graph:]]+\s*:\s*([[:graph:]]+)`)
	reClassMemberLine = regexp.MustCompile(`\s*([[:graph:]]+)\s*([[:graph:]]+);\s*//\s*([[:graph:]]+)`)
	reClassSize = regexp.MustCompile(`static_assert\s*\(\s*sizeof\s*\(\s*[[:graph:]]+\s*==\s*(.*)\s*,`)
}

func GetClasses(inputFolder string) ([]Class, error) {
	classes := []Class{}

	err := filepath.Walk(inputFolder, func(path string, info os.FileInfo, _ error) error {
		if info.IsDir() || !strings.HasSuffix(info.Name(), ".hpp") {
			return nil
		}

		fmt.Println("Parsing", inputFolder+info.Name())

		data, err := os.ReadFile(inputFolder + info.Name())
		if err != nil {
			return err
		}

		class, err := parseClass(string(data))
		if err != nil {
			return err
		}

		classes = append(classes, class)

		return nil
	})

	return classes, err
}

func parseClass(data string) (Class, error) {
	className := reClassName.FindStringSubmatch(data)
	if len(className) < 2 {
		return Class{}, fmt.Errorf("Class name cannot be found")
	}

	classParentName := reClassParentName.FindStringSubmatch(data)
	if len(classParentName) < 2 {
		// Need to add two entries, because we are reading [1] in case there is a parent.
		// But TObject does not have a parent, so leave it empty in that case
		classParentName = append(classParentName, "")
		classParentName = append(classParentName, "")
	}

	members, err := parseClassMembers(reClassMemberLine.FindAllStringSubmatch(data, -1))
	if err != nil {
		return Class{}, err
	}

	classSize := reClassSize.FindStringSubmatch(data)
	if len(classSize) < 2 {
		return Class{}, fmt.Errorf("Class size cannot be found")
	}

	return Class{
		Name:    className[1],
		Parent:  classParentName[1],
		Members: members,
		Size:    classSize[1],
	}, nil
}

func parseClassMembers(data [][]string) ([]ClassMember, error) {
	members := make([]ClassMember, len(data))

	for i := 0; i < len(data); i++ {
		if len(data[i]) < 4 {
			return members, fmt.Errorf("Class member n°%d is not valid: %s", i, data[i])
		}

		members[i] = ClassMember{
			Type:   data[i][1],
			Name:   data[i][2],
			Offset: data[i][3],
		}
	}

	return members, nil
}
