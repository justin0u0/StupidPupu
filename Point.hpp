#ifndef POINT_HPP
#define POINT_HPP

// Can be used as 2D coordinate point or 2D vector
struct Point {
	float x, y;
	explicit Point();
	explicit Point(float x, float y);
	Point(const Point&) = default;
	Point& operator=(const Point&) = default;
	bool operator==(const Point& rhs);
	bool operator!=(const Point& rhs);
	Point& operator+=(const Point& rhs);
	Point& operator-=(const Point& rhs);
	Point& operator*=(const int& rhs);
	Point& operator*=(const float& rhs);
};
Point const operator+(Point const& lhs, Point const& rhs);
Point const operator-(Point const& lhs, Point const& rhs);
Point const operator*(Point const& lhs, int const& rhs);
Point const operator*(Point const& lhs, float const& rhs);
#endif

