/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:49:22 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 13:22:42 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _guard(false) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "[ScavTrap]: ScaveTrap constructor called: " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap]: ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& cpy): ClapTrap(cpy._name) {
	std::cout << "[ScavTrap]: cpy constructor caled: " << _name << std::endl;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
	_attackDamage = cpy._attackDamage;
	_guard = cpy._guard;
}

ScavTrap ScavTrap::operator=(ScavTrap& cpy) {
	std::cout << "[ScavTrap]: operator = called: " << cpy._name << std::endl;
	if (this != &cpy)
	{
		this->_name = cpy._name;
		this->_attackDamage = cpy._attackDamage;
		this->_energyPoints = cpy._energyPoints;
		this->_hitPoints = cpy._hitPoints;
		this->_guard = cpy._guard;
	}
	return *this;
}

void ScavTrap::guardGate() {
	if (_guard == true)
		std::cout << "[ScavTrap]: " << _name << " is already in Guard keeper mode" << std::endl;
	else {
		std::cout << "[ScavTrap]: " << _name << " is now in Gate keeper mode." << std::endl;
		_guard = true;
	}
}

void ScavTrap::attack(std::string target) {
		if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "[ScavTrap]: ScavTrap " << _name;
		std::cout << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "[ClapTrap]: ClapTrap " << _name << " can't attack." << std::endl;
}