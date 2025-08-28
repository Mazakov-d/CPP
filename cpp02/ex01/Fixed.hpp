/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/28 11:19:37 by dmazari          ###   ########.fr       */
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


	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);


#endif