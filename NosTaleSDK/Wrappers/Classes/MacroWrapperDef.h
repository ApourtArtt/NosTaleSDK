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
    TENTWELL_NAME* obj{ nullptr };\
protected:\
    WRAPPER_NAME(bool)/*std::shared_ptr default constructor enforces us to use a type here*/\
    {\
        initObject();\
    }\
    WRAPPER_NAME() {\
        isManaging_ = true;\
    }\
    void initObjectRecursive()\
    {\
        WRAPPER_PARENT_NAME::initObjectRecursive();\
        initObject();\
    }\
public:\
    WRAPPER_NAME(TENTWELL_NAME* TEntwell) : WRAPPER_PARENT_NAME(TEntwell) {\
        obj = TEntwell;\
    }\
    WRAPPER_NAME(std::shared_ptr<NosTaleSDK::Interfaces::VTableProvider> Provider) : WRAPPER_PARENT_NAME()\
    {\
        uintptr_t vTable = Provider->Get("NosTaleSDK::Entwell::Classes::"#TENTWELL_NAME"::VTable");\
        obj = new TENTWELL_NAME;\
        obj->vTable = vTable;\
        WRAPPER_PARENT_NAME::SetInternal(obj);\
        initObjectRecursive();\
    }\
    virtual ~WRAPPER_NAME()\
    {\
        if (isManaging_ && obj != nullptr)\
        {\
            delete obj;\
            obj = nullptr;\
            isManaging_ = false;\
        }\
    }\
    virtual void SetInternal(TENTWELL_NAME* TEntwell) { obj = TEntwell; WRAPPER_PARENT_NAME::SetInternal(TEntwell); }\
    virtual TENTWELL_NAME* GetInternal() { return obj; }\
private:

/*

    WRAPPER_NAME(uintptr_t VTable) : WRAPPER_PARENT_NAME(true)\
    {\
        obj = new TENTWELL_NAME; \
        obj->vTable = VTable; \
        WRAPPER_PARENT_NAME::SetInternal(obj); \
        initObject(); \
    }\
*/