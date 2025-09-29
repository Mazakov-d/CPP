/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:55:02 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/29 11:42:00 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F> void iter(T* array, const std::size_t size, F f(T)) {
	for (std::size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif