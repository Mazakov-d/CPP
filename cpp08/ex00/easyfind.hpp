/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:26:09 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/17 16:18:37 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

template <typename T> int	easyfind(const T&, int);

class NotInContainer: public std::exception {
	public:
		virtual const char *what() const throw();
};

# include "easyfind.tpp"

#endif