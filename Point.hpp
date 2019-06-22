#ifndef POINT_HPP
#define POINT_HPP

// Can be used as 2D coordinate point or 2D vector
struct Point {
	float x, y;
	explicit Point();
	explicit Point(float x, float y);
	bool operator==(const Point& rhs);
	bool operator!=(const Point& rhs);
	Point& operator+=(const Point& rhs);
	Point& operator+(const Point& rhs);
	Point& operator-=(const Point& rhs);
	Point& operator-(const Point& rhs);
	Point& operator*=(const int& rhs);
	Point& operator*(const int& rhs);
	Point& Round();
};
#endif

