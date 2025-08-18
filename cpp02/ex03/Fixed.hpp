/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/17 19:26:07 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
	int _fixedPoint;
	static const int _fractionalBits = 8;

	public:
	Fixed();
	Fixed(const int intValue);
	Fixed(const float fltValue);
	Fixed(const Fixed& cpy);
	Fixed& operator=(const Fixed& cpy);
	~Fixed();

	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator>(const Fixed& other) const ;
	bool operator<(const Fixed& other) const ;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);


	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed& min(Fixed& a, Fixed&b);
	static const Fixed& min(const Fixed& a, const Fixed&b);
	static Fixed& max(Fixed& a, Fixed&b);
	static const Fixed& max(const Fixed& a, const Fixed &b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);


#endif