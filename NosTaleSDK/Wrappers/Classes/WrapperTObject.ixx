module;
#include "stdint.h"
export module WrapperTObject;
import TObject;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTObject
    {
    private:
        TObject* obj;
    public:
        WrapperTObject() {}
        WrapperTObject(TObject* to) : obj(to) {}
        WrapperTObject(uintptr_t vT)
        {
            obj = new TObject();
            obj->vTable = vT;
        }
        WrapperTObject(TObject* to, uintptr_t vT)
        {
            obj = to;
            obj->vTable = vT;
        }
        virtual ~WrapperTObject()
        {
            if (isManaging && obj != nullptr)
            {
                delete obj;
                obj = nullptr;
                isManaging = false;
            }
        }

        virtual void SetInternal(TObject* to) { obj = to; }
        virtual TObject* GetInternal() { return obj; }

        void SetVTable(uintptr_t VT) { obj->vTable = VT; }
        virtual uintptr_t GetVTable() { return obj->vTable; }

    protected:
        bool isManaging{ false };
    };
}