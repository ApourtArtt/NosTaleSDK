//SDKBridgeBuilder:IGNORE

template<typename T>
class BaseWrapper
{
public:
    BaseWrapper() {}
    BaseWrapper(T* TEntwell, bool IsManaged = false)
        : isManaged(IsManaged)
        , tEntwell(TEntwell)
    {}
    virtual ~BaseWrapper()
    {
        if (isManaged && tEntwell)
        {
            delete tEntwell;
            tEntwell = nullptr;
        }
    }

private:
    bool isManaged{ false };
    T* tEntwell{ nullptr };
};

template<class T>
class Wrapper : public BaseWrapper<T>
{
};