/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:30:10 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 00:36:00 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie::randomChump(std::string name) {
	Zombie *zombie;

	zombie = Zombie::newZombie(name);
	std::cout << zombie->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	delete[] zombie;
}

int main(int ac, char **av) {
	int i = 1;
	Zombie zombie;

	while (i < ac) {
		zombie.randomChump(av[i]);
		i++;
	}
}