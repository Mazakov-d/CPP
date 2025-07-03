/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:03:38 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/03 00:39:03 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int	_fixedPoint;
		static const int _fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const int cstInt);
		Fixed(const float cstFlt);
		Fixed(const Fixed& cpy);
		Fixed& operator=(const Fixed& c);
		~Fixed(void);

		friend std::ostream& operator<<(std::ostream& os, const Fixed& fp);

		bool operator>=(const Fixed& other) const ;
		bool operator<=(const Fixed& other) const ;
		bool operator>(const Fixed& other) const ;
		bool operator<(const Fixed& other) const ;
		bool operator==(const Fixed& other) const ;
		bool operator!=(const Fixed& other) const ;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

#endif
