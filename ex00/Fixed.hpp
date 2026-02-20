/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:45:29 by dev               #+#    #+#             */
/*   Updated: 2026/02/20 14:12:23 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
	int	_fixedPointValue;
	static const int _fractionalBits = 8;

public:
	// default constructor
	Fixed();

	// copy constructor
	Fixed(const Fixed& other);

	// copy assignement operator overload
	Fixed& operator=(const Fixed& other);

	// destructor
	~Fixed();

	int	getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif