/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:03:38 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/02 13:37:15 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

#endif
