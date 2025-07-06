/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:27:06 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/04 15:03:13 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {
	
}

Point::~Point() {

}

Point::Point(const float x, const float y): _x(x), _y(y) {
	
}

Point::Point(const Point& cpy): _x(cpy._x), _y(cpy._y) {

}

Point& Point::operator=(const Point& cpy)m{
	return (*this);
}

Fixed Point::getX() const {
	return (_x);
}

Fixed Point::getY() const {
	return (_y);
}