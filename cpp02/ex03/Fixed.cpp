/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:29:20 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/03 12:43:11 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _fixedPoint(0) {
}

Fixed::Fixed(const int cstInt) {
	_fixedPoint = cstInt * (1 << _fractionalBits);
}

Fixed::Fixed(const float cstFlt) {
	_fixedPoint = roundf(cstFlt * (1 << _fractionalBits) );
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(const Fixed& cpy) {
	this->operator=(cpy);
}

Fixed& Fixed::operator=(const Fixed& c) {
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
	return (_fixedPoint >> _fractionalBits);
}

bool Fixed::operator>=(const Fixed& other) const {
	return _fixedPoint >= other._fixedPoint;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _fixedPoint <= other._fixedPoint;
}

bool Fixed::operator>(const Fixed& other) const {
	return _fixedPoint > other._fixedPoint;
}

bool Fixed::operator<(const Fixed& other) const {
	return _fixedPoint < other._fixedPoint;
}

bool Fixed::operator==(const Fixed& other) const {
	return _fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;

	result._fixedPoint = this->_fixedPoint + other._fixedPoint;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;

	result._fixedPoint = this->_fixedPoint - other._fixedPoint;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;

	result._fixedPoint = (this->_fixedPoint * other._fixedPoint) >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;

	long long dividend = static_cast<long long>(this->_fixedPoint) << _fractionalBits;
	result._fixedPoint = static_cast<int>(dividend / other._fixedPoint);
	return result;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (a);
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::operator++() {
	_fixedPoint++;
	return *this;
}

Fixed& Fixed::operator--() {
	_fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}
