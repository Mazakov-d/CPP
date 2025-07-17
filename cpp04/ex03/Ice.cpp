/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:16:46 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/17 22:38:54 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {
	
}

Ice::~Ice() {
	
}

Ice::Ice(const Ice& cpy): AMateria("ice") {
	
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Ice* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
