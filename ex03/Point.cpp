#include "Point.hpp"

Point::Point(){}

Point::Point( const float num_x, const float num_y ) : x(num_x), y(num_y){}

Point::Point(const Point & origin) : x(origin.getRawBitsX()),y(origin.getRawBitsY()) {}

Point::~Point(){}

Fixed Point::getRawBitsX() const
{
	return (this->x);
}

Fixed Point::getRawBitsY() const
{
	return(this->y);
}