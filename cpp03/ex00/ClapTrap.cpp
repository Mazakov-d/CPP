/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:20:47 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/05 14:00:33 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackdamage(0) {
	std::cout << "New ClapTrap: " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << _name << " get destructed..." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy) {
	std::cout << "Copy constructor of " << cpy._name << std::endl;
	_name = cpy._name;
	_hitPoints = cpy._hitPoints;
	_energyPoints = cpy._energyPoints;
	_attackdamage = cpy._attackdamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& cpy) {
	if (this != &cpy)
	{
		std::cout << "Class operator= called, cpy name: " << cpy._name << std::endl;
		_name = cpy._name;
		_hitPoints = cpy._hitPoints;
		_energyPoints = cpy._energyPoints;
		_attackdamage = cpy._attackdamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " attacks " << target << ", causing ";
		std::cout << _attackdamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << "can't attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " get attacked, causing " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " << _name << " is already down." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap" << _name;
		std::cout << " repairs " << amount << " energy points." << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " can't repairs." << std::endl;
}