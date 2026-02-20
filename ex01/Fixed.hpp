/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:45:38 by dev               #+#    #+#             */
/*   Updated: 2026/02/20 14:12:48 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int	_fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);

	~Fixed();

	int	getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fix);

#endif