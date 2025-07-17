/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:20:07 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/17 22:41:42 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {

}

Cure::~Cure() {

}

Cure::Cure(const Cure& cpy): AMateria("cure") {
	
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Cure* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}