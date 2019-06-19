#ifndef POINT_HPP
#define POINT_HPP

struct Point {
	float x, y;
	explicit Point();
	explicit Point(float x, float y);
	bool operator==(const Point& rhs);
	bool operator!=(const Point& rhs);
};
#endif

