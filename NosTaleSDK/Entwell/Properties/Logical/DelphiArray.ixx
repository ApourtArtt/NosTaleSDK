module;
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstring>
export module DelphiArray;

namespace NosTaleSDK::Entwell::Properties::Logical
{
    export template<typename T>
    class DelphiArray
    {
    public:
        DelphiArray(const std::vector<T>& arr) : data(arr) {}
        DelphiArray() : DelphiArray({}) {}
        DelphiArray(T* arr)
        {
            int32_t length = *(int32_t*)((char*)(arr - sizeof(int32_t)));
            data.reserve(length);
            for (int32_t i = 0; i < length; i++)
            {
                auto ptr = (char*)(arr)+i * sizeof(T);
                auto ptr2 = *(T*)(ptr);
                data.push_back(*(T*)(ptr));
            }
        }

        T* ToInternal()
        {
            char* output = (char*)malloc(sizeof(int32_t) + (data.size() * sizeof(T)));
            if (!output)
                return nullptr;

            *(int32_t*)(output) = data.size() * sizeof(T);
            output += sizeof(int32_t);

            for (int32_t i = 0; i < data.size(); i++)
            {
                memcpy((void*)(output + i * sizeof(T)), (void*)&data[i], sizeof(T));
            }

            return (T*)output;
        }

        std::vector<T> GetData() { return data; }

        void SetData(const std::vector<T>& arr) { data = arr; }

    private:
        std::vector<T> data;
    };

    export template<typename T>
    class DelphiArrayRefCounted
    {
    public:
        DelphiArrayRefCounted(const std::vector<T>& arr, int32_t refCount) : ref(refCount), data(arr) {}
        DelphiArrayRefCounted() : DelphiArrayRefCounted({}, 0) {}
        DelphiArrayRefCounted(T* arr)
        {
            ref = *(int32_t*)((char*)(arr - sizeof(int32_t) * 2));;
            int32_t length = *(int32_t*)((char*)(arr - sizeof(int32_t)));
            data.reserve(length);
            for (int32_t i = 0; i < length; i++)
            {
                auto ptr = (char*)(arr)+i * sizeof(T);
                auto ptr2 = *(T*)(ptr);
                data.push_back(*(T*)(ptr));
            }
        }

        T* ToInternal()
        {
            char* output = (char*)malloc(sizeof(int32_t) * 2 + (data.size() * sizeof(T)));
            if (!output)
                return nullptr;

            *(int32_t*)(output) = ref;
            output += sizeof(int32_t);
            *(int32_t*)(output) = data.size() * sizeof(T);
            output += sizeof(int32_t);

            for (int32_t i = 0; i < data.size(); i++)
            {
                memcpy((void*)(output + i * sizeof(T)), (void*)&data[i], sizeof(T));
            }

            return (T*)output;
        }

        std::vector<T> GetData() { return data; }
        int32_t GetRefCount() { return ref; }

        void SetData(const std::vector<T>& arr) { data = arr; }
        void SetRefCount(int32_t refCount) { ref = refCount; }

    private:
        int32_t ref;
        std::vector<T> data;
    };
}