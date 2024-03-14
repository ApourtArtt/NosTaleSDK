package main

import (
	"fmt"

	"github.com/ApourtArtt/NosTaleSDK/SDKBridgeBuilder/class_manager"
	"github.com/ApourtArtt/NosTaleSDK/SDKBridgeBuilder/wrapper_manager"
)

func main() {
	fmt.Println("Parsing classes")

	classes, err := class_manager.GetClasses("./input/class/")
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("Executing classes templates")

	if err := class_manager.CreateClasses("./output/class/", "./templates/class", classes); err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("All classes were successfully generated")

	fmt.Println("Parsing wrappers")

	wrappers, err := wrapper_manager.GetWrappers("./input/wrapper/")

	fmt.Println("now")
	fmt.Println(wrappers, err)

	wrapper_manager.CreateWrappers("./output/wrapper/", "./templates/wrapper/", wrappers, classes)
}
