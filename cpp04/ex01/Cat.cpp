/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:09:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:41:00 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	_brain = new Brain();
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(Cat& cpy) {
	_brain = cpy._brain;
	_type = cpy._type;
	std::cout << "Cat: Copy constructor called: " << cpy._type << std::endl;
}

Cat& Cat::operator=(Cat& cpy) {
	std::cout << "Cat: operator = called." << std::endl;
	if (this != &cpy)
	{
		this->_type = cpy._type;
		this->_brain = cpy._brain;
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat: Destructor called." << std::endl;
}