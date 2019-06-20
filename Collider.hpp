#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "Point.hpp"
#include "IObject.hpp"

class Collider {
	bool PointInBitmap(const Point p, ALLEGRO_BITMAP* bmp);
	bool PointInRectangle(const Point p, const Point rect_left_up, const Point rect_right_down);
	bool RectangleOverlap(const Point min1, const Point max1, const Point min2, const Point max2);
};
#endif

