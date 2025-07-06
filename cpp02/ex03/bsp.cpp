/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:36:39 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/06 14:29:50 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed sign(const Point& p1, const Point& p2, const Point& p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c , Point const point) {
	Fixed d1, d2, d3;
	bool has_neg, has_pos;

	if (point == a || point == b || point == c) {
		return false;
	}
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > 0);
	return !(has_neg && has_pos);
}