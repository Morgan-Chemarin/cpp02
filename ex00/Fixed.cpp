/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:45:25 by dev               #+#    #+#             */
/*   Updated: 2026/02/20 14:12:15 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// default constructor
Fixed::Fixed(): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// copy assignement operator overload
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();

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
	return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}