#include "Point.hpp"

Point::Point() : Point(0, 0) {
}
Point::Point(float x, float y): x(x), y(y) {
}
bool Point::operator==(const Point& rhs) {
	return x == rhs.x && y == rhs.y;
}
bool Point::operator!=(const Point& rhs) {
	return !operator==(rhs);
}

