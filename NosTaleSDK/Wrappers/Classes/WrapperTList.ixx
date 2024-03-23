module;
#include "MacroWrapperDef.h"
#include <memory>
export module WrapperTList;
import WrapperTObject;
import VTableProvider;
import TList;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export template <typename T>
        class WrapperTList : public WrapperTObject
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTList, WrapperTObject, TList<T>);
    public:
        void insert(T Item, uint32_t Index) noexcept
        {
            ++obj_->length;
            if (obj_->length >= obj_->capacity)
                obj_->capacity *= 2;

            T* newItems = static_cast<T*>(malloc(obj_->capacity * sizeof(T)));
            auto i = 0;

            for (; i < obj_->index && i < obj_->length; i++)
                newItems[i] = obj_->items[i];

            newItems[i] = obj_->item;

            for (; i < obj_->length; i++)
                newItems[i + 1] = obj_->items[i];

            obj_->items = newItems;
        }

        void pushBack(T Item) noexcept
        {
            if (obj_->capacity <= obj_->length)
                reserve();
            obj_->items[obj_->length] = Item;
            obj_->length += 1;
        }
        
        void reserve()
        {
            obj_->capacity *= 2;

            T* newItems = static_cast<T*>(malloc(obj_->capacity * sizeof(T)));

            for (auto i = 0; i < obj_->length; i++)
                newItems[i] = obj_->items[i];

            obj_->items = newItems;
        }

        uint32_t size()
        {
            return obj_->length;
        }

        T getItem(int Index) noexcept
        {
            if (Index >= obj_->length || Index < 0)
                return NULL;
            return obj_->items[Index];
        }

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHiddenFunction
        void initObject()
        {

        }
    };
}