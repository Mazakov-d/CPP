/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:03:38 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/01 16:05:26 by dmazari          ###   ########.fr       */
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
		Fixed(const Fixed& cpy);
		Fixed& operator=(const Fixed& c);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif