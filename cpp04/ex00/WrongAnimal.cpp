/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:43:00 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:30:33 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Human") {
	
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy): _type(cpy._type) {
	std::cout << "WrongAnimal: Copy constructor called: " << _type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& cpy) {
	std::cout << "WrongAnimal: Operator '=' called: " << cpy._type << std::endl;
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong Sound" << std::endl;
}