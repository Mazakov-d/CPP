/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:57:51 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 14:05:04 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
	int N = 5;
	std::string name = "Foo";
	int i = 0;
	Zombie zombie;
	Zombie* Horde = zombie.zombieHorde(N, name);

	while (i < N)
	{
		Horde[i].annouce();
		i++;
	}
	delete[] Horde;
}