module;
#include "MacroWrapperDef.h"
#include <memory>
#include <random>
export module WrapperTEWCustomPanelWidget;
import WrapperTEWMoveWidget;
import TEWCustomPanelWidget;
import VTableProvider;
import ImagePadding;
import PictureView;
import PictureDisplay;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWCustomPanelWidget : public WrapperTEWMoveWidget
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWCustomPanelWidget, WrapperTEWMoveWidget, TEWCustomPanelWidget);
    public:
        void SetImagePadding(const Entwell::Properties::Graphical::ImagePadding& ImagePadding) const { obj_->imagePadding = ImagePadding; }
        

        //9 Parts view
        void SetComplexViews(const Entwell::Properties::Graphical::PictureView& Center,
                             const Entwell::Properties::Graphical::PictureView& TopLeft,
                             const Entwell::Properties::Graphical::PictureView& TopMiddle,
                             const Entwell::Properties::Graphical::PictureView& TopRight,
                             const Entwell::Properties::Graphical::PictureView& MiddleRight,
                             const Entwell::Properties::Graphical::PictureView& BottomRight,
                             const Entwell::Properties::Graphical::PictureView& BottomMiddle,
                             const Entwell::Properties::Graphical::PictureView& BottomLeft,
                             const Entwell::Properties::Graphical::PictureView& MiddleLeft) const
        {
            obj_->nbUsablePictureViews = 9;
            SetPictureViews({
                Center,
                TopLeft,
                TopMiddle,
                TopRight,
                MiddleRight,
                BottomRight,
                BottomMiddle,
                BottomLeft,
                MiddleLeft
            });

            obj_->imagePadding = Entwell::Properties::Graphical::ImagePadding(
                GetWidth() - MiddleLeft.width - MiddleRight.width,
                GetHeight() - TopMiddle.height - BottomMiddle.height,
                GetWidth() - MiddleLeft.width,
                GetHeight() - TopMiddle.height,
                MiddleLeft.width,
                TopMiddle.height,
                MiddleRight.width,
                BottomMiddle.height
            );

            obj_->unknown23 = 5;
        }

    private:
        // ReSharper disable once CppMemberFunctionMayBeStatic
        // ReSharper disable once CppHidingFunction
        void initObject()
        {
            
        }
    };
}