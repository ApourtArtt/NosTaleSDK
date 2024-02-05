module;
#include <vector>
#include <cstring>
export module DelphiArray;

namespace NosTaleSDK::Entwell::Properties::Logical
{
    export template<typename T>
    class DelphiArray
    {
    public:
        explicit DelphiArray(const std::vector<T>& Arr) : data_(Arr) {}
        DelphiArray() : DelphiArray({}) {}

        explicit DelphiArray(T* Arr)
        {
            int32_t length = *reinterpret_cast<int32_t*>(static_cast<char*>(Arr - sizeof(int32_t)));
            data_.reserve(length);
            for (int32_t i = 0; i < length; i++)
            {
                auto ptr = static_cast<char*>(Arr)+i * sizeof(T);
                auto ptr2 = *static_cast<T*>(ptr);
                data_.push_back(*static_cast<T*>(ptr));
            }
        }

        T* ToInternal()
        {
            auto output = static_cast<char*>(malloc(sizeof(int32_t) + (data_.size() * sizeof(T))));
            if (!output)
                return nullptr;

            *reinterpret_cast<int32_t*>(output) = data_.size() * sizeof(T);
            output += sizeof(int32_t);

            for (int32_t i = 0; i < data_.size(); i++)
            {
                memcpy(output + i * sizeof(T), static_cast<void*>(&data_[i]), sizeof(T));
            }

            return reinterpret_cast<T*>(output);
        }

        std::vector<T> GetData() { return data_; }

        void SetData(const std::vector<T>& Arr) { data_ = Arr; }

    private:
        std::vector<T> data_;
    };

    export template<typename T>
    class DelphiArrayRefCounted
    {
    public:
        DelphiArrayRefCounted(const std::vector<T>& Arr, const int32_t RefCount) : ref_(RefCount), data_(Arr) {}
        DelphiArrayRefCounted() : DelphiArrayRefCounted({}, 0) {}

        explicit DelphiArrayRefCounted(T* Arr)
        {
            ref_ = *reinterpret_cast<int32_t*>(static_cast<char*>(Arr - sizeof(int32_t) * 2));;
            int32_t length = *reinterpret_cast<int32_t*>(static_cast<char*>(Arr - sizeof(int32_t)));
            data_.reserve(length);
            for (int32_t i = 0; i < length; i++)
            {
                auto ptr = static_cast<char*>(Arr)+i * sizeof(T);
                auto ptr2 = *static_cast<T*>(ptr);
                data_.push_back(*static_cast<T*>(ptr));
            }
        }

        T* ToInternal()
        {
            auto output = static_cast<char*>(malloc(sizeof(int32_t) * 2 + (data_.size() * sizeof(T))));
            if (!output)
                return nullptr;

            *reinterpret_cast<int32_t*>(output) = ref_;
            output += sizeof(int32_t);
            *reinterpret_cast<int32_t*>(output) = data_.size() * sizeof(T);
            output += sizeof(int32_t);

            for (int32_t i = 0; i < data_.size(); i++)
            {
                memcpy(output + i * sizeof(T), static_cast<void*>(&data_[i]), sizeof(T));
            }

            return static_cast<T*>(output);
        }

        std::vector<T> GetData() { return data_; }
        int32_t GetRefCount() const { return ref_; }

        void SetData(const std::vector<T>& Arr) { data_ = Arr; }
        void SetRefCount(const int32_t RefCount) { ref_ = RefCount; }

    private:
        int32_t ref_;
        std::vector<T> data_;
    };
}