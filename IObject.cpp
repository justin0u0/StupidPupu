#include "Point.hpp"
#include "IObject.hpp"

IObject::IObject(float x, float y, float w, float h, float anchorX, float anchorY)
	: position(Point(x, y)), size(Point(w, h)), anchor(Point(anchorX, anchorY)) {
}

void IObject::Draw() const {
}

void IObject::Update(float deltaTime) {
}

Point IObject::LeftUpCorner() const{
	Point p(position.x - anchor.x * size.x, position.y - anchor.y * size.y);
	return p;
} 

Point IObject::RightDownCorner() const{
	Point p(position.x + (1 - anchor.x) * size.x, position.y + (1 - anchor.y) * size.y);
	return p;
}

