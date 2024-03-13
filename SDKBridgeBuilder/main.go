package main

import (
	"fmt"

	"github.com/ApourtArtt/NosTaleSDK/SDKBridgeBuilder/class_manager"
)

func main() {
	classes, err := class_manager.GetClasses("./input/TEntwell/")
	if err != nil {
		fmt.Println(err)
		return
	}

	if err := class_manager.CreateClasses("./output/TEntwell/", "./templates", classes); err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("All classes were successfully generated")
}
