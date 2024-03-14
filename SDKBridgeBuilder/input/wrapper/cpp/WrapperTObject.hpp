#include "BaseWrapper.hpp"
#include "../../class/TObject.hpp"
#include <vector>

namespace NosTaleSDK::Wrappers
{
    template <>
    class Wrapper<Entwell::DelphiClasses::TObject> : public BaseWrapper<Entwell::DelphiClasses::TObject>
    {
    public:
    void setVisible(bool Visible) { visible = Visible; }
    bool getVisible() { return visible; }

    private:
        bool visible{ false };
        std::vector<int> eeeeeeeeeeeeeeeeeeeeeeee;
    };
}
