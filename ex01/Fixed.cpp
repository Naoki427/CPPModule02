#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_num = 0;
}

Fixed::Fixed(const Fixed & origin)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_num = origin.getRawBits();
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_num = num << this->bit;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_num = roundf(num *(1 << this->bit));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed & origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin)
	{
		this->fixed_point_num = origin.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return this->fixed_point_num;
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_point_num = raw;
}
float Fixed::toFloat( void ) const
{
	return ((float)this->fixed_point_num /(1 << this->bit));
}

int Fixed::toInt( void ) const
{
	return (this->fixed_point_num /(1 << this->bit));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}