/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:43:00 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:30:45 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Human") {
	
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	
}

WrongAnimal::WrongAnimal(WrongAnimal& cpy): _type(cpy._type) {
	
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& cpy) {
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
	if (_type == "Cat")
		std::cout << "Woof" << std::endl;
	if (_type == "Human")
		std::cout << "Peace" << std::endl;
}