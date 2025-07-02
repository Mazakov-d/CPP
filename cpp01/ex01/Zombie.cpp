/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:52:25 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 13:54:18 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	
}

Zombie::~Zombie() {
	
}

void Zombie::annouce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}