/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:32:59 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/10/28 00:31:08 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"
# include <algorithm>

const char* NotInContainer::what() const throw() {
	return ("Not in container.");
}

template <typename T>
int	easyfind(const T& t, int n)
{
	typename T::const_iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw (NotInContainer());
	return *it;
}

#endif