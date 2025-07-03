/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:24:41 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/03 12:49:11 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;


	public:
		Point();
		Point(const float fx, const float fy);
		Point(const Point& cpy);
		Point& operator=(const Fixed& c);
		~Point();

		bool operator==(const Point& other) const ;
		friend std::ostream& operator<<(std::ostream& os, const Point& p);

		float getXValue();
		float getYValue();
		float sign(Point p1, Point p2, Point p3);
		bool pointInTriangle(Point const& p1, Point const& p2, Point const& p3);
};

#endif