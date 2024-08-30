#pragma once
#include <stdint.h>
#include <string_view>
#include "../../Utils/StringObfuscator.hpp"
#include "../../Interfaces/VTableProvider.hpp"

namespace NosTaleSDK::Entwell::Classes
{
#pragma pack(push, 1)
	// https://docwiki.embarcadero.com/Libraries/Sydney/en/System.TObject
	class TObject
	{
	public:
		static inline const std::string NAME{ obf("TObject") };
		TObject(std::shared_ptr<Interfaces::VTableProvider> VTableProvider);
		TObject(uintptr_t VTableAddress);

		uintptr_t getVTable() const;

		template<typename T>
		static T* deepCopy(T* Object)
		{
			T* output = new T;
			memcpy(output, Object, sizeof(*Object));
			return output;
		}

	protected:
		uintptr_t vTable; // 0x00
	};
	static_assert(sizeof(TObject) == 0x4);
	static_assert(sizeof(TObject) <= 0x4, "TObject's size is higher than 0x4.");
	static_assert(sizeof(TObject) >= 0x4, "TObject's size is lower than 0x4.");
#pragma pack(pop)
}