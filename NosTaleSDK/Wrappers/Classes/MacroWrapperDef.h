#pragma once

// It unfortunately does not work to export/import/using namespace in a macro :(
#define TENTWELL_WRAPPER_IMPORT(WRAPPER_NAME, WRAPPER_PARENT_NAME, TENTWELL_NAME) \
export module WRAPPER_NAME;\
import WRAPPER_PARENT_NAME;\
import TENTWELL_NAME;\
import VTableProvider;\
using namespace NosTaleSDK::Entwell::Classes;

#define TENTWELL_WRAPPER_DEFINITION(WRAPPER_NAME, WRAPPER_PARENT_NAME, TENTWELL_NAME) \
private:\
    TENTWELL_NAME* obj_{ nullptr };\
protected:\
    WRAPPER_NAME() {\
        isManaging_ = true;\
    }\
    void initObjectRecursive()\
    {\
        WRAPPER_PARENT_NAME::initObjectRecursive();\
        initObject();\
    }\
public:\
    WRAPPER_NAME(TENTWELL_NAME* TEntwell) : WRAPPER_PARENT_NAME(TEntwell)\
    {\
        obj_ = TEntwell;\
    }\
    WRAPPER_NAME(std::shared_ptr<NosTaleSDK::Interfaces::VTableProvider> Provider) : WRAPPER_PARENT_NAME()\
    {\
        uintptr_t vTable = Provider->Get("NosTaleSDK::Entwell::Classes::"#TENTWELL_NAME"::VTable");\
        obj_ = new TENTWELL_NAME;\
        obj_->vTable = vTable;\
        WRAPPER_PARENT_NAME::SetInternal(obj_);\
        initObjectRecursive();\
    }\
    virtual ~WRAPPER_NAME()\
    {\
        if (isManaging_ && obj_ != nullptr)\
        {\
            delete obj_;\
            obj_ = nullptr;\
            isManaging_ = false;\
        }\
    }\
    virtual void SetInternal(TENTWELL_NAME* TEntwell) { obj_ = TEntwell; WRAPPER_PARENT_NAME::SetInternal(TEntwell); }\
    virtual TENTWELL_NAME* GetInternal() { return obj_; }\
private: