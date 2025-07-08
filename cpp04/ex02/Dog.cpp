/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:17:03 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:32:55 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	_brain = new Brain();
	std::cout << "Dog: Default constructor is called." << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy) {
	_brain = new Brain(*cpy._brain);
	std::cout << "Dog: Copy constructor called: " << _type << std::endl;
}

Dog& Dog::operator=(const Dog& cpy) {
	std::cout << "Dog: operator = called." << std::endl;
	if (this != &cpy) {
		Animal::operator=(cpy);
		delete _brain;
		_brain = new Brain(*cpy._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog: Destructor called." << std::endl;
}