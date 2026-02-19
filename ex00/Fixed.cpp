#include "Fixed.hpp"
#include <iostream>

// default constructor
Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // ou liste d'initialisation ?
}

// copy assignement operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits(); // ou other._value ?

	std::cout << "Copy assignment operator called" << std::endl;

	return (*this);
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}