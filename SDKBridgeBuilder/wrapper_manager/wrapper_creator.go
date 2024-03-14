package wrapper_manager

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"text/template"

	"github.com/ApourtArtt/NosTaleSDK/SDKBridgeBuilder/class_manager"
)

func findWrapperByName(wrappers []Wrapper, className string) (Wrapper, error) {
	for i := 0; i < len(wrappers); i++ {
		if wrappers[i].Name == className {
			return wrappers[i], nil
		}
	}
	return Wrapper{}, fmt.Errorf("cannot find wrapper %s", className)
}

func findParentByName(childClassName string, wrappers []Wrapper, classes []class_manager.Class) (bool, Wrapper, class_manager.Class, error) {
	class, err := class_manager.FindClassByName(classes, childClassName)
	if err != nil {
		return false, Wrapper{}, class_manager.Class{}, err
	}

	if class.Parent == "" {
		return false, Wrapper{}, class_manager.Class{}, nil
	}

	parent, err := class_manager.FindClassByName(classes, class.Parent)
	if err != nil {
		return false, Wrapper{}, class_manager.Class{}, err
	}

	wrapper, err := findWrapperByName(wrappers, parent.Name)
	if err != nil {
		return false, Wrapper{}, class_manager.Class{}, err
	}
	return true, wrapper, parent, nil
}

func createWrapperInheritance(wrapper Wrapper, wrappers []Wrapper, classes []class_manager.Class) (Wrapper, error) {
	currentName := wrapper.Name

	for {
		hasParent, w, c, err := findParentByName(currentName, wrappers, classes)
		if err != nil {
			return Wrapper{}, err
		}
		if !hasParent {
			break
		}

		currentName = c.Name

		for include := range w.Includes {
			wrapper.Includes[include] = struct{}{}
		}

		wrapper.PrivateBlock.Functions = w.PrivateBlock.Functions + wrapper.PrivateBlock.Functions
		wrapper.PrivateBlock.Variables = w.PrivateBlock.Variables + wrapper.PrivateBlock.Variables

		wrapper.PublicBlock.Functions = w.PublicBlock.Functions + wrapper.PublicBlock.Functions
		wrapper.PublicBlock.Variables = w.PublicBlock.Variables + wrapper.PublicBlock.Variables

		wrapper.ProtectedBlock.Functions = w.ProtectedBlock.Functions + wrapper.ProtectedBlock.Functions
		wrapper.ProtectedBlock.Variables = w.ProtectedBlock.Variables + wrapper.ProtectedBlock.Variables
	}

	return wrapper, nil
}

func CreateWrappers(outputFolder, templatesFolder string, wrappers []Wrapper, classes []class_manager.Class) error {
	err := filepath.Walk(templatesFolder, func(path string, info os.FileInfo, _ error) error {
		if info.IsDir() || !strings.HasSuffix(info.Name(), ".tmpl") {
			return nil
		}

		fmt.Println("Executing", templatesFolder+"/"+info.Name())

		data, err := os.ReadFile(templatesFolder + "/" + info.Name())
		if err != nil {
			return err
		}

		parts := strings.Split(info.Name(), ".")
		if len(parts) < 3 {
			return fmt.Errorf("filename for %s is not valid", info.Name())
		}

		filename := strings.Join(parts[0:len(parts)-3], ".")
		folderName := parts[len(parts)-3]
		extension := parts[len(parts)-2]

		os.MkdirAll(outputFolder+"/"+folderName, 0777)

		for i := 0; i < len(wrappers); i++ {
			tmpl, err := template.New(folderName).Parse(string(data))
			if err != nil {
				return err
			}

			wrapper, err := createWrapperInheritance(wrappers[i], wrappers, classes)
			if err != nil {
				return err
			}

			fn := strings.ReplaceAll(filename, "{{.Name}}", wrapper.Name)

			f, err := os.Create(outputFolder + "/" + folderName + "/" + fn + "." + extension)
			if err != nil {
				return err
			}
			defer func() {
				f.Close()
			}()

			if err := tmpl.Execute(f, wrapper); err != nil {
				return err
			}
		}

		return nil
	})

	return err
}
