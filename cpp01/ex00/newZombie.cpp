/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:15:21 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 13:41:41 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name) {
	Zombie* zombie = new Zombie();
	zombie->_name = name;
	return zombie;
}