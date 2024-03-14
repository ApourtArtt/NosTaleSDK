package wrapper_manager

type ClassBlock struct {
	Functions string
	Variables string
}

type Wrapper struct {
	Name           string
	Includes       map[string]struct{}
	PublicBlock    ClassBlock
	PrivateBlock   ClassBlock
	ProtectedBlock ClassBlock
}
