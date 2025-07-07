/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:04:57 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:31:20 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Human") {
	std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(std::string name): _type(name) {
	std::cout << "Animal: Default constructor called: " << _type << std::endl;
}

Animal::Animal(Animal& cpy): _type(cpy._type) {
	std::cout << "Animal: Copy constructor called: " << _type << std::endl;
}

Animal& Animal::operator=(Animal& cpy) {
	std::cout << "Aminal: Operator '=' called: " << cpy._type << std::endl;
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const {
	if (_type == "Cat")
		std::cout << "Meoow" << std::endl;
	if (_type == "Dog")
		std::cout << "Woof" << std::endl;
	if (_type == "Human")
		std::cout << "War !" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}