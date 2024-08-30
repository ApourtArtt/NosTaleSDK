#include "PictureView.hpp"

namespace NosTaleSDK::Entwell::Structs
{
	PictureViewer::PictureViewer(std::vector<PictureView> PictureViews)
	{
		for (size_t i = 0; i < PictureViews.size() && i < 30; i++)
			pictureViews[i] = PictureViews[i];
		nbPictureViews = static_cast<int16_t>(PictureViews.size());
	}
}