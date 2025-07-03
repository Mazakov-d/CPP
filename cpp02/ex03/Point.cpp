/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:28:23 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/03 12:50:42 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {
	
}

Point::Point(const float fx, const float fy): _x(fx * 256), _y(fy * 256) {
	
}

Point::Point(const Point& cpy): _x(cpy._x), _y(cpy._y) {
	
}

Point::~Point() {
	
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p._x << ", " << p._y << ")" << std::endl;
	return (os);
}


float Point::getXValue() {
	return (this->_x.toFloat());
}

float Point::getYValue() {
	return (this->_y.toFloat());
}

float Point::sign (Point p1, Point p2, Point p3)
{
	return (p1._x.toFloat() - p3._x.toFloat()) * (p2._y.toFloat() - p3._y.toFloat()) - (p2._x.toFloat() - p3._x.toFloat()) * (p1._y.toFloat() - p3._y.toFloat());
}

bool Point::pointInTriangle (Point const& p1, Point const& p2, Point const& p3)
{
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(*this, p1, p2);
	d2 = sign(*this, p2, p3);
	d3 = sign(*this, p3, p1);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}

bool Point::operator==(const Point& other) const {
	if ((other._x == this->_x) && (other._y == this->_y))
		return (true);
	return (false);
}