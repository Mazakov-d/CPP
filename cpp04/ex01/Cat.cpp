/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:09:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:32:13 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	_brain = new Brain();
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy) {
	_brain = new Brain(*cpy._brain);
	std::cout << "Cat: Copy constructor called: " << _type << std::endl;
}

Cat& Cat::operator=(const Cat& cpy) {
	std::cout << "Cat: operator = called." << std::endl;
	if (this != &cpy) {
		Animal::operator=(cpy);
		delete _brain;
		_brain = new Brain(*cpy._brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat: Destructor called." << std::endl;
}