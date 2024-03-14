#include "BaseWrapper.hpp"
#include "../../class/TPersistent.hpp"
#include <string>

namespace NosTaleSDK::Wrappers
{
    template <>
    class Wrapper<Entwell::DelphiClasses::TPersistent> : public BaseWrapper<Entwell::DelphiClasses::TPersistent>
    {
    public:
        void menfou() {}
    private:
        std::string baaaaaaaaa;
    };
}