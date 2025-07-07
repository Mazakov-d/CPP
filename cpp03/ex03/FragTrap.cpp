/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:14:01 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 14:21:07 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::~FragTrap() {
	
}


FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "[FragTrap]: constructor called: " << _name << std::endl;
	_hitPoints = 100;
	_attackDamage = 30;
	_energyPoints = 100;
}

FragTrap::FragTrap(FragTrap& cpy): ClapTrap(cpy._name) {
	std::cout << "[FragTrap]: cpy construcotr called: " << _name << std::endl;
	_attackDamage = cpy._attackDamage;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
}

FragTrap FragTrap::operator=(FragTrap& cpy) {
	std::cout << "[FragTrap]: operator = called: " << cpy._name << std::endl;
	if (this != &cpy)
	{
		this->_name = cpy._name;
		this->_attackDamage = cpy._attackDamage;
		this->_energyPoints = cpy._energyPoints;
		this->_hitPoints = cpy._hitPoints;
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap]: " << _name << " shouts: By the power of Claptrap, I summon... a HIGH FIVE! ✋⚡" << std::endl;
}