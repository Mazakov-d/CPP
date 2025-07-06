/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:27:22 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/06 14:28:50 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
	Fixed const _x;
	Fixed const _y;

	public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point& cpy);

	bool operator==(const Point& other) const;

	Fixed getX() const;
	Fixed getY() const;
};

#endif