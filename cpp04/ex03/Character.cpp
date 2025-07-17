/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:42:09 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/18 00:02:30 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name): _name(name), _trashedI(0), _equipement(0) {
	for (int i = 0; i < 4; i++)
		_materias[i] = nullptr;
	
}

Character::~Character() {
	int i = 0;
	while (i < 4)
	{
		if (_materias[i])
			delete(_materias[i]);
		i++;
	}
	i = 0;
	while (i < _trashedI)
	{
		delete(_trash[i]);
		i++;
	}
}

Character::Character(const Character& cpy): _name(cpy._name) {
	int i = 0;
	while (i < 4)
	{
		if (cpy._materias[i])
			_materias[i] = cpy._materias[i]->clone();
		else
			_materias[i] = nullptr;
		i++;
	}
	i = 0;
	while (i < cpy._trashedI)
	{
		if (cpy._trash[i])
			_trash.push_back(cpy._trash[i]->clone());
		else
			_trash.push_back(nullptr);
		i++;
	}
	_equipement = cpy._equipement;
	_trashedI = cpy._trashedI;
}

Character& Character::operator=(const Character& other) {
	if (this != &other)
	{
		_name = other._name;
		int i = 0;
		while (i < 4)
		{
			if (this->_materias[i])
				delete(this->_materias[i]);
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			i++;
		}
		i = 0;
		while (i < other._trashedI)
		{
			if (i < this->_trashedI)
				delete(this->_trash[i]);
			if (i < this->_trashedI)
				this->_trash[i] = other._trash[i]->clone();
			else
				this->_trash.push_back(other._trash[i]->clone());
			i++;
		}
		_equipement = other._equipement;
		_trashedI = other._trashedI;
	}
	return *this;
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (_equipement >= 4)
	{
		std::cout << "Can't equip that, too much equipments" << std::endl;
		return ;
	}
	int i = 0;
	while (i < 4)
	{
		if (!_materias[i])
		{
			_materias[i] = m->clone();
		}
		i++;
	}
	_equipement++;
}

void Character::unequip(int idx) {
	if (_equipement == 0)
		return ;
	if (!(0 <= idx < 4))
		return ;
	if (!_materias[idx])
		return ;
	_trash.push_back(_materias[idx]);
	_materias[idx] = nullptr;
	_equipement--;
	_trashedI++;
}

void Character::use(int idx, ICharacter& target) {
	if (!(0 <= idx < 4))
		return ;
	if (!_materias[idx])
		return ;
	_materias[idx]->use(target);
}