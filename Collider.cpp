#include <allegro5/allegro.h>

#include "Point.hpp"
#include "Collider.hpp"

bool Collider::PointInBitmap(const Point p, ALLEGRO_BITMAP* bmp) {
	return al_get_pixel(bmp, p.x, p.y).a != 0;
}
bool Collider::PointInRectangle(const Point p, const Point rect_left_up, const Point rect_right_down) {
	return (p.x >= rect_left_up.x && p.x < rect_right_down.x && p.y >= rect_left_up.y && p.y < rect_right_down.y);
}
bool Collider::RectangleOverlap(const Point min1, const Point max1, const Point min2, const Point max2) {
	return (max1.x > min2.x && max2.x > min1.x && max1.y > min2.y && max2.y > min2.y); 	
}
