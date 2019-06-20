#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "Point.hpp"
#include "IObject.hpp"

class Collider {
	bool PointInBitmap(const Point p, const ALLEGRO_BITMAP* bmp);
	bool PointInObject(const Point p, const IObject* object);
	bool ObjectOverlap(const IObject* obj1, const IObject* obj2);
};
#endif

