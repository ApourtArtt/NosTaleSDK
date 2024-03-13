package class_manager

type ClassMember struct {
	Type    string
	Name    string
	Offset  string
	Comment string
}

type Class struct {
	Name    string
	Parent  string
	Members []ClassMember
	Size    string
}
