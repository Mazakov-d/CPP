/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/04 12:28:48 by dorianmazar      ###   ########.fr       */
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

	friend std::ostream& operator<<(std::ostream& os, const Fixed& f);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

#endif