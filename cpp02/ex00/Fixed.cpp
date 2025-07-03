/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:29:20 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/02 22:51:24 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _fixedPoint(0) {
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& cpy) {
	std::cout << "Copy constructor called\n";
	this->operator=(cpy);
}

Fixed& Fixed::operator=(const Fixed& c) {
	std::cout << "Copy assignment operator called\n";
	if (this != &c) {
		_fixedPoint = c.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member called\n";
	return _fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member called\n";
	_fixedPoint = raw;
}
