#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point
{
private:
	const Fixed x; 
	const Fixed y; 
public:
	Point();
	Point( const float num_x, const float num_y );
	Point(const Point & origin);
	~Point();
	Fixed getRawBitsX() const;
	Fixed getRawBitsY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif