/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:04:57 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:31:48 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Human") {
	std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(std::string name): _type(name) {
	std::cout << "Animal: Default constructor called: " << _type << std::endl;
}

Animal::Animal(const Animal& cpy): _type(cpy._type) {
	std::cout << "Animal: Copy constructor called: " << _type << std::endl;
}

Animal& Animal::operator=(const Animal& cpy) {
	std::cout << "Animal: Operator '=' called: " << cpy._type << std::endl;
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Good Sound" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}