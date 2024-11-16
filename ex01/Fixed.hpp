#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
private:
	int	fixed_point_num;
	static const int	bit = 8;  
public:
	Fixed(void);
	Fixed(const Fixed & origin);
	Fixed(const int num);
	Fixed(const float num);
	Fixed& operator = (const Fixed & origin);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif