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
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_num;
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_point_num = raw;
}