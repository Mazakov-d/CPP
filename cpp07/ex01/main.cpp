/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:55:30 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/16 15:06:10 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	disp_char(char c)
{
	std::cout << c;
}

void	square(int i)
{
	std::cout << i * i << std::endl;
}

int main() {
	char	str[] = "salut la vie";
	int		array[] = {2, 4, 6, 123};

	::iter(str, 9, disp_char);
	std::cout << std::endl;
	::iter(array, 4, square);
}