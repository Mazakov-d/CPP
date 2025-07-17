/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:43:49 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/18 00:11:07 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materias[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {
	int i = 0;
	while (i < 4)
	{
		if (_materias[i])
			delete(_materias[i]);
		i++;
	}
}

MateriaSource::MateriaSource(const MateriaSource& cpy) {
	for (int i = 0; i < 4; i++) {
		if (cpy._materias[i])
			_materias[i] = cpy._materias[i]->clone();
		else
			_materias[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_materias[i])
				delete(_materias[i]);
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = nullptr;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_materias[i]) {
			_materias[i] = m->clone();
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type) {
			return _materias[i]->clone();
		}
	}
	return nullptr;
}
