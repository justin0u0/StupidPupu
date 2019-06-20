#include "ImageButton.hpp"
#include "Loader.hpp"
#include "Point.hpp"

ImageButton::ImageButton(std::string imgOut, std::string imgIn, float x, float y, float w, float h, float anchorX, float anchorY)
	: Image(imgOut, x, y, w, h, anchorX, anchorY)
	, image_out(Loader::GetInstance().GetBitmap(imgOut))
	, image_in(Loader::GetInstance().GetBitmap(imgIn)) {
}
void ImageButton::SetOnClick(std::function<void(void)> onclick) {
	this->onclick = onclick;
}
void ImageButton::OnMouseDown(int button, int mx, int my) {
	if (Enabled && (button & 1) && mouseIn) {
		if (onclick)
			onclick();
	}
}
void ImageButton::OnMouseMove(int mx, int my) {
	mouseIn = Collider::PointInBitmap(Point(mx, my), image_out);
	bmp = (Enabled && mouseIn) ? image_in : image_out;
}

