#include "TObject.hpp"

namespace NosTaleSDK::Entwell::Classes
{
	TObject::TObject(std::shared_ptr<Interfaces::VTableProvider> VTableProvider)
		: vTable(VTableProvider->Get(NAME))
	{}

	TObject::TObject(uintptr_t VTableAddress)
		: vTable(VTableAddress)
	{}

	uintptr_t TObject::getVTable() const
	{
		return vTable;
	}
}
