/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:32:59 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/17 16:20:51 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

const char *what() throw() {
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