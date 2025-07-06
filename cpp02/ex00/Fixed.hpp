/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/03 15:53:40 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
	int _fixedPoint;
	static const int _fractionalBits = 8;

	public:
	Fixed();
	Fixed(const Fixed& cpy);
	Fixed& operator=(const Fixed& cpy);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif