/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:09:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:29:38 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy) {
	std::cout << "Cat: Copy constructor called: " << _type << std::endl;
}

Cat& Cat::operator=(const Cat& cpy) {
	std::cout << "Cat: Operator '=' called: " << cpy._type << std::endl;
	if (this != &cpy)
		Animal::operator=(cpy);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called." << std::endl;
}