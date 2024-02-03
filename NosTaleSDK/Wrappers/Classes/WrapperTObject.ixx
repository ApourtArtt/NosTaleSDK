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
        TObject* obj_;
    public:
        WrapperTObject(): obj_(nullptr)
        {
        }

        explicit WrapperTObject(TObject* To) : obj_(To) {}

        explicit WrapperTObject(const uintptr_t VT)
        {
            obj_ = new TObject();
            obj_->vTable = VT;
        }
        WrapperTObject(TObject* To, const uintptr_t VT)
        {
            obj_ = To;
            obj_->vTable = VT;
        }
        virtual ~WrapperTObject()
        {
            if (isManaging_ && obj_ != nullptr)
            {
                delete obj_;
                obj_ = nullptr;
                isManaging_ = false;
            }
        }

        virtual void SetInternal(TObject* To) { obj_ = To; }
        virtual TObject* GetInternal() { return obj_; }

        void SetVTable(const uintptr_t VT) const { obj_->vTable = VT; }
        virtual uintptr_t GetVTable() { return obj_->vTable; }

    protected:
        void initObjectRecursive() {}
        bool isManaging_{ false };
    };
}