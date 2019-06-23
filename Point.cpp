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
Point& Point::operator-=(const Point& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
Point& Point::operator*=(const int& rhs) {
	x *= rhs;
	y *= rhs;
	return *this;
}
Point& Point::operator*=(const float& rhs) {
	x *= rhs;
	y *= rhs;
	return *this;
}
Point const operator+(Point const& lhs, Point const& rhs) {
	return Point(lhs) += rhs;
}
Point const operator-(Point const& lhs, Point const& rhs) {
	return Point(lhs) -= rhs;
}
Point const operator*(Point const& lhs, int const& rhs) {
	return Point(lhs) *= rhs;
}
Point const operator*(Point const& lhs, float const& rhs) {
	return Point(lhs) *= rhs;
}
float Distance(Point const& lhs, Point const& rhs) {
	return sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

