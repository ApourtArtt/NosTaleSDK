# SDK Bridge Builder

## What is it about?
One of NosTale SDK's goal is to be polyglot. It should be possible to create PlugIns/BlockIns with several languages (current target: C, C++, Rust, Zig).\
Another reason is, making an interface for the C++ API is kind of tricky because the support for modules/macros combined is a pity with any IDE. We can remove the need of macros with the generation as we are removing the manual verbosity through this tool.\
If an update from Entwell, or from NosTale SDK's team is modifying the structure of the core, it will have an impact on every languages' API.\
This project is creating the structure of the API dynamically, the generator is written in Golang, with the base API in C++ dicted by Golang's template engine.

## Languages supported
None. But C++ soon!

## How can I contribute?
The classes are not subject to regular changes, we are not accepting any pull requests to fix them if they break, as it might impact the whole SDK, but also the PlugIns/BlockIns.\
However, we are accepting pull requests for new functions on the wrappers. Let's say we have this:\
```cpp
template<>
class Wrapper<TLBSWidget> : BaseWrapper<TLBSWidget>
{
public:
    // ...
private:
    // ...
};
```
And you notice there is a need to have a function to change the visibility of a TLBSWidget (notice the TLBSWidget has a `bool _isVisible`), then, you could submit a pull request looking like:\
```cpp
template<>
class Wrapper<TLBSWidget> : BaseWrapper<TLBSWidget>
{
public:
    // ...
    void setVisible(bool _isVisible)
    {
        tEntwell->isVisible = _isVisible;
    }

private:
    // ...
};
```