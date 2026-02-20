/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:45:41 by dev               #+#    #+#             */
/*   Updated: 2026/02/20 14:21:52 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a(2);
	Fixed b(10);
	Fixed c;
	Fixed const d(Fixed(5.05f) * Fixed(2));

	std::cout << a + b << std::endl; // 12
	std::cout << b - a << std::endl; // 8
	std::cout << b / a << std::endl; // 5
	std::cout << a * b << std::endl << std::endl; // 20

	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl << std::endl;

	std::cout << d << std::endl << std::endl;

	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;

	return 0;
}
