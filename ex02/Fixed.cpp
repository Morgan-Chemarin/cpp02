/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:45:36 by dev               #+#    #+#             */
/*   Updated: 2026/02/20 12:31:17 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _fixedPointValue(0) {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();

	return (*this);
}

Fixed::~Fixed() {}

Fixed::Fixed(const int n)
{
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	this->_fixedPointValue = static_cast<float>(roundf(f * (1 << this->_fractionalBits)));
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return (this->_fixedPointValue / static_cast<float>((1 << (this->_fractionalBits))));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}


bool Fixed::operator>(const Fixed &other) const  
{
	return this->_fixedPointValue > other._fixedPointValue; 
}

bool Fixed::operator<(const Fixed &other) const  
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const 
{
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const 
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const 
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const 
{
	return this->_fixedPointValue != other._fixedPointValue;
}


Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}


Fixed& Fixed::operator++(void)
{
	++this->_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fixedPointValue;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	--this->_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fixedPointValue;
	return temp;
}


Fixed& Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return first;
	else
		return second;
}

const Fixed& Fixed::min( const Fixed &first, const Fixed &second)
{
	if (first < second)
		return first;
	else
		return second;
}

Fixed& Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return first;
	else
		return second;
}

const Fixed& Fixed::max( const Fixed &first, const Fixed &second)
{
	if (first > second)
		return first;
	else
		return second;
}

std::ostream& operator<<(std::ostream &o, const Fixed &fix)
{
    o << fix.toFloat();
    return (o);
}