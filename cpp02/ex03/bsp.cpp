/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:36:39 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/16 17:04:04 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(const Point& p1, const Point& p2, const Point& p3) {
	float area = ((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
		+ p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
		+ p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2);

	return area < 0 ? -area : area;
}

bool bsp( Point const a, Point const b, Point const c , Point const point) {
	float area1, area2, area3, mainArea;

	mainArea = area(a, b, c);
	area1 = area(point, a, b);
	area2 = area(point, b, c);
	area3 = area(point, c, a);
	
	if (area1== 0 || area2 == 0 || area3 == 0)
		return false;
	else if (mainArea == area3 + area2 + area1)
		return true;

	return false;
}