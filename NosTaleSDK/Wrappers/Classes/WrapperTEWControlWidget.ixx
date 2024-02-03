module;
#include "MacroWrapperDef.h"
#include <memory>
#include <Windows.h>
export module WrapperTEWControlWidget;
import WrapperTLBSWidget;
import TEWControlWidget;
import VTableProvider;
import Bgra;
import ImageData;
import PictureDisplay;
import PictureView;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWControlWidget : public WrapperTLBSWidget
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWControlWidget, WrapperTLBSWidget, TEWControlWidget)
    public:
        void SetImageName(const int32_t ImageName) const { obj->imageData.imageName = ImageName; }
        int32_t GetImageName() const { return obj->imageData.imageName; }

    private:
        void initObject()
        {
            obj->color = Entwell::Properties::Graphical::Bgra(255, 255, 255, 255);
            obj->imageData = Entwell::Properties::Graphical::ImageData(
                0,
                0,
                512,
                512,
                nullptr
            );
        }
    };
}
