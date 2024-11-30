#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point_num = 0;
}

Fixed::Fixed(const Fixed & origin)
{
	*this = origin;
}

Fixed::Fixed(const int num)
{
	this->fixed_point_num = num << this->bit;
}

Fixed::Fixed(const float num)
{
	this->fixed_point_num = roundf(num *(1 << this->bit));
}
Fixed::~Fixed(){}

Fixed& Fixed::operator = (const Fixed & origin)
{
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

bool Fixed::operator > (const Fixed& other) const
{
	return this->fixed_point_num > other.getRawBits();
}

bool Fixed::operator < (const Fixed& other) const
{
	return this->fixed_point_num < other.getRawBits();
}

bool Fixed::operator >= (const Fixed& other) const
{
	return this->fixed_point_num >= other.getRawBits();
}

bool Fixed::operator <= (const Fixed& other) const
{
	return this->fixed_point_num <= other.getRawBits();
}

bool Fixed::operator == (const Fixed& other) const
{
	return this->fixed_point_num == other.getRawBits();
}

bool Fixed::operator != (const Fixed& other) const
{
	return this->fixed_point_num == other.getRawBits();
}

Fixed Fixed::operator + (const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator - (const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator * (const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator / (const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	++this->fixed_point_num;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixed_point_num++;
	return temp;
}

Fixed& Fixed::operator--()
{
	--this->fixed_point_num;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixed_point_num--;
	return temp;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	return (num1.getRawBits() < num2.getRawBits()) ? num1 : num2;
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() < num2.getRawBits()) ? num1 : num2;
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	return (num1.getRawBits() > num2.getRawBits()) ? num1 : num2;
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return (num1.getRawBits() > num2.getRawBits()) ? num1 : num2;
}