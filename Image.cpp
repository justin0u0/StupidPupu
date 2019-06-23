#include <allegro5/allegro.h>

#include "Image.hpp"
#include "IObject.hpp"
#include "Loader.hpp"
#include "Point.hpp"

Image::Image(std::string img, float x, float y, float w, float h, float anchorX, float anchorY) :
	IObject(x, y, w, h, anchorX, anchorY) {
	if (size.x == 0 && size.y == 0) {
		bmp = Loader::GetInstance().GetBitmap(img);
		size.x = GetBitmapWidth();
		size.y = GetBitmapHeight();
	} else if (size.x == 0) {
		bmp = Loader::GetInstance().GetBitmap(img);
		size.x = GetBitmapWidth() * size.y / GetBitmapHeight();
	} else if (size.y == 0) {
		bmp = Loader::GetInstance().GetBitmap(img);
		size.y = GetBitmapHeight() * size.x / GetBitmapWidth();
	} else {
		bmp = Loader::GetInstance().GetBitmap(img, size.x, size.y);
	}
}
// al_draw_scaled_bitmap(bitmap pointer, sx, sy, sw, sh, dx, dy, dw, dh, flags)
// sx, sy, sw, sh: source position(x,y) + size(w,h)
// dx, dt, dw, dh: destination position(x,y) + size(x,y)
// change the image's position and size
void Image::Draw() const {
	if (visible) {
		al_draw_scaled_bitmap(bmp, 0, 0, GetBitmapWidth(), GetBitmapHeight()
			, position.x - anchor.x * size.x
			, position.y - anchor.y * size.y
			, size.x, size.y, 0);
	}
}
int Image::GetBitmapWidth() const {
	return al_get_bitmap_width(bmp);
}
int Image::GetBitmapHeight() const {
	return al_get_bitmap_height(bmp);
}
void Image::ChangeImage(std::string new_img) {
	bmp = Loader::GetInstance().GetBitmap(new_img, size.x, size.y);
}

