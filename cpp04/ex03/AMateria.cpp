/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:06:13 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/17 23:58:00 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type): _type(type) {
	
}

AMateria::~AMateria() {
	
}

AMateria::AMateria(const AMateria& cpy): _type(cpy._type) {
	
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

std::string const& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "Should not see this" << std::endl;
}