/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:42:38 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/16 14:45:49 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> T min(T& a, T&b) {
	return (a < b) ? a : b;
}

template <typename T> T max(T&a, T&b) {
	return (a > b) ? a : b;
}

template <typename T> void swap(T&a, T&b) {
	T	save;

	save = a;
	a = b;
	b = save;
}

#endif