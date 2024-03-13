package class_manager

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
	"text/template"
)

func findClassByName(classes []Class, className string) (Class, error) {
	for i := 0; i < len(classes); i++ {
		if classes[i].Name == className {
			return classes[i], nil
		}
	}
	return Class{}, fmt.Errorf("cannot find class %s", className)
}

func mergeParentMembersWithChild(class Class, classes []Class) (Class, error) {
	for parent := class.Parent; len(parent) > 0; {
		parentClass, err := findClassByName(classes, parent)
		if err != nil {
			return class, err
		}

		for i := 0; i < len(parentClass.Members); i++ {
			parentClass.Members[i].Comment = "Inherited from " + parentClass.Name
		}

		parent = parentClass.Parent
		class.Members = append(parentClass.Members, class.Members...)
	}

	return class, nil
}

func CreateClasses(outputFolder, templatesFolder string, classes []Class) error {
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

		for i := 0; i < len(classes); i++ {
			tmpl, err := template.New(folderName).Parse(string(data))
			if err != nil {
				return err
			}

			class, err := mergeParentMembersWithChild(classes[i], classes)
			if err != nil {
				return err
			}

			fn := strings.ReplaceAll(filename, "{{.Name}}", class.Name)

			f, err := os.Create(outputFolder + "/" + folderName + "/" + fn + "." + extension)
			if err != nil {
				return err
			}
			defer func() {
				f.Close()
			}()

			if err := tmpl.Execute(f, class); err != nil {
				return err
			}
		}

		return nil
	})
	return err
}
