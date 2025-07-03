/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:29:20 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/02 23:47:27 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _fixedPoint(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int cstInt) {
	std::cout << "Int constructor called\n";
	_fixedPoint = cstInt * (1 << _fractionalBits);
}

Fixed::Fixed(const float cstFlt) {
	std::cout << "Float constructor called\n";
	_fixedPoint = roundf(cstFlt * (1 << _fractionalBits) );
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

std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
	os << fp.toFloat();
	return os;
}


int Fixed::getRawBits( void ) const {
	return _fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
	_fixedPoint = raw;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(_fixedPoint) / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const {
	return (_fixedPoint >> (1 * _fractionalBits));
}