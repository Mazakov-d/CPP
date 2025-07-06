/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:30:20 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/06 14:30:32 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	// std::cout << "Int constructor called" << std::endl;
	_fixedPoint = intValue << _fractionalBits;
}

Fixed::Fixed(const float fltValue) {
	// std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(fltValue * (1 << _fractionalBits));

}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed& Fixed::operator=(const Fixed& cpy) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (&cpy != this)
		this->_fixedPoint = cpy.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _fixedPoint;
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits member function called" << std::endl;
	_fixedPoint = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_fixedPoint) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _fixedPoint >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	os << f.toFloat();
	return os;
}

bool Fixed::operator!=(const Fixed& other) const {
	if (this->getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& other)  const {
	if (this->getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& other) const {
	if (this->getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& other) const {
	if (this->getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed& other) const {
	if (this->getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& other) const {
	if (this->getRawBits() < other.getRawBits())
		return (true);
	return (false);
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
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other._fixedPoint == 0) {
		std::cerr << "Division by zero." << std::endl;
		return (Fixed());
	}

	Fixed result;

	long long dividend = static_cast<long long>(this->_fixedPoint) << _fractionalBits;
	result._fixedPoint = static_cast<int>(dividend / other._fixedPoint);
	return result;
}

Fixed& Fixed::operator++() {
	_fixedPoint++;
	return *this;
}

Fixed& Fixed::operator--() {
	_fixedPoint--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a > b)
		return (b);
	return (a);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a > b)
		return (b);
	return (a);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a < b)
		return (b);
	return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a < b)
		return (b);
	return (a);
}
