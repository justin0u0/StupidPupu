#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <allegro5/bitmap.h>
#include <string>

#include "IObject.hpp"

class Image : public IObject {
public:
	ALLEGRO_BITMAP* bmp;
	explicit Image(std::string img, float x, float y, float w=0, float h=0, float anchorX=0, float anchorY=0);
	void Draw() const override;
	int GetBitmapWidth() const;
	int GetBitmapHeight() const;
};
#endif

