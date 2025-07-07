/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:17:03 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:29:12 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog: Default constructor is called." << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy) {
	std::cout << "Dog: Copy constructor called: " << _type << std::endl;
}

Dog& Dog::operator=(const Dog& cpy) {
	std::cout << "Dog: Operator '=' called: " << cpy._type << std::endl;
	if (this != &cpy)
		Animal::operator=(cpy);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called." << std::endl;
}