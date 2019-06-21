#include <allegro5/allegro.h>
#include "Sprite.hpp"

Sprite::Sprite(std::string img, float x, float y, float w, float h, float anchorX, float anchorY
	, float rotation, float vx, float vy, float r, float g, float b, float a, int flag)
	: Image(img, x, y, w, h, anchorX, anchorY), rotation(rotation)
	, velocity(Point(vx, vy)), tint(al_map_rgba(r, g, b, a)), flag(flag) {
}
void Sprite::Draw() const {
	if (visible) {
		al_draw_tinted_scaled_rotated_bitmap(bmp, tint, anchor.x * GetBitmapWidth(), anchor.y * GetBitmapHeight()
			, position.x, position.y, size.x / GetBitmapWidth(), size.y / GetBitmapHeight(), rotation, flag);
	}
}
void Sprite::Update(float deltaTime) {
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
}
