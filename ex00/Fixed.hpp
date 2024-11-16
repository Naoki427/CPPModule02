#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{
private:
	int	fixed_point_num;
	static const int	bit = 8;  
public:
	Fixed(void);
	Fixed(const Fixed & origin);
	Fixed& operator = (const Fixed & origin);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};


#endif