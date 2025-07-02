/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:30:10 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 13:46:44 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie::randomChump(std::string name) {
	Zombie *zombie;

	zombie = Zombie::newZombie(name);
	zombie->announce();
	delete zombie;
}

