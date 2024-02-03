module;
#include "MacroWrapperDef.h"
#include <memory>
#include <random>
export module WrapperTEWCustomPanelWidget;
import WrapperTEWControlWidgetEvent;
import TEWCustomPanelWidget;
import VTableProvider;
import ImagePadding;
import PictureView;
import PictureDisplay;

namespace NosTaleSDK::Wrappers::Classes
{
    using namespace NosTaleSDK::Entwell::Classes;
    export class WrapperTEWCustomPanelWidget : public WrapperTEWControlWidgetEvent
    {
        TENTWELL_WRAPPER_DEFINITION(WrapperTEWCustomPanelWidget, WrapperTEWControlWidgetEvent, TEWCustomPanelWidget)
    public:
        void SetImagePadding(const Entwell::Properties::Graphical::ImagePadding& ImagePadding) const { obj->imagePadding = ImagePadding; }
        

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
            if (!obj->imageData.pictureViews)
                obj->imageData.pictureViews = new Entwell::Properties::Graphical::PictureDisplay();

            obj->imageData.pictureViews->nbPictureViews = 9;
            obj->imageData.pictureViews->pictureViews[0] = Center;
            obj->imageData.pictureViews->pictureViews[1] = TopLeft;
            obj->imageData.pictureViews->pictureViews[2] = TopMiddle;
            obj->imageData.pictureViews->pictureViews[3] = TopRight;
            obj->imageData.pictureViews->pictureViews[4] = MiddleRight;
            obj->imageData.pictureViews->pictureViews[5] = BottomRight;
            obj->imageData.pictureViews->pictureViews[6] = BottomMiddle;
            obj->imageData.pictureViews->pictureViews[7] = BottomLeft;
            obj->imageData.pictureViews->pictureViews[8] = MiddleLeft;

            obj->imagePadding = Entwell::Properties::Graphical::ImagePadding(
                GetWidth() - MiddleLeft.width - MiddleRight.width,
                GetHeight() - TopMiddle.height - BottomMiddle.height,
                GetWidth() - MiddleLeft.width,
                GetHeight() - TopMiddle.height,
                MiddleLeft.width,
                TopMiddle.height,
                MiddleRight.width,
                BottomMiddle.height
            );
        }

    private:
        void initObject()
        {

        }
    };
}