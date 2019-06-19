#include "Point.hpp"
#include "IObject.hpp"

IObject::IObject(float x, float y, float w, float h, float anchorX, float anchorY)
	: position(Point(x, y)), size(Point(w, h)), anchor(Point(anchorX, anchorY)) {
}

void IObject::Draw() const {
}

void IObject::Update(float deltaTime) {
}
