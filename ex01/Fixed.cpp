#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = static_cast<float>(roundf(f * (1 << this->_fractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed_point_value = other.getRawBits();

	std::cout << "Copy assignment operator called" << std::endl;

	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point_value;
}

void Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
	return (_fixed_point_value / static_cast<float>((1 << (_fractionalBits))));
}

int Fixed::toInt(void) const
{
	return (this->_fixed_point_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fix)
{
    o << fix.toFloat();
    return (o);
}