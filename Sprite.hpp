#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Image.hpp"

// Image that supports rotaion, velocity, tint and collision radius
class Sprite : public Image {
public:
	// Rotation angle in radians
	float rotation;
	// Pixel per second
	Point velocity;
	// Color tint
	ALLEGRO_COLOR tint;
	// Assume a circle is a good approximation of the sprite's boundary
	float hitbox_radius = 0;
	// Flip flag: 0/ALLEGRO_FLIP_VERTICAL/ALLEGRO_FLIP_HORIZONTAL
	int flag;
	// Constructor
	explicit Sprite(std::string img, float x, float y, float w=0, float h=0, float anchorX=0.5, float anchorY=0.5,
		float rotation=0, float vx=0, float vy=0, float r=255, float g=255, float b=255, float a=255, int flag=0);
	void Draw() const override;
	void Update(float deltaTime) override;	
};
#endif

