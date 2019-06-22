#include <cmath>
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
Point& Point::operator+=(const Point& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}
Point& Point::operator+(const Point& rhs) {
	return (*this) += rhs;
}
Point& Point::operator-=(const Point& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
Point& Point::operator-(const Point& rhs) {
	return (*this) -= rhs;
}
Point& Point::operator*=(const int& rhs) {
	x *= rhs;
	y *= rhs;
	return *this;
}
Point& Point::operator*(const int& rhs) {
	return (*this) *= rhs;
}
Point& Point::Round() {
	x = std::round(x);
	y = std::round(y);
	return *this;
}

