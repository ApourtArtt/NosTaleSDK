module;
#include <algorithm>

#include "MacroWrapperDef.h"
#include <memory>
#include <vector>
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
        void SetImageName(const int32_t ImageName) const { obj_->imageData.imageName = ImageName; }
        int32_t GetImageName() const { return obj_->imageData.imageName; }

        void SetPictureViews(const std::vector<Entwell::Properties::Graphical::PictureView>& Views) const
        {
            if (!obj_->imageData.pictureViews)
                obj_->imageData.pictureViews = new Entwell::Properties::Graphical::PictureDisplay();

            for (auto i = 0; i < Views.size(); i++)
            {
                obj_->imageData.pictureViews->pictureViews[i] = Views[i];
            }
            
            obj_->imageData.nbPictureViews = Views.size();
            obj_->imageData.pictureViews->nbPictureViews = Views.size();
        }

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject() const
        {
            obj_->color = Entwell::Properties::Graphical::Bgra(255, 255, 255, 255);
            obj_->imageData = Entwell::Properties::Graphical::ImageData(
                0,
                0,
                512,
                512,
                nullptr
            );
        }
    };
}
