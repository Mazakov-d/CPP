/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:27:06 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/06 14:29:04 by mazakov          ###   ########.fr       */
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

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}

bool Point::operator==(const Point& other) const {
	return (_x == other._x && _y == other._y);
}