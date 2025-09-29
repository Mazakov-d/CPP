/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:32:59 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/29 12:26:20 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

const char* NotInContainer::what() const throw() {
	return ("Not in container.");
}

template <typename T>
int	easyfind(const T& t, int n)
{
	int x;

	for (typename T::const_iterator it = t.begin(); it != t.end(); ++it)
	{
		x = *it;
		if (x == n)
			return x;
	}
	throw NotInContainer();
}

#endif