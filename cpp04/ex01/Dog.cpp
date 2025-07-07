/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:17:03 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:41:21 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	_brain = new Brain();
	std::cout << "Dog: Default constructor is called." << std::endl;
}

Dog::Dog(Dog& cpy) {
	_brain = cpy._brain;
	_type = cpy._type;
	std::cout << "Dog: Copy constructor called." << std::endl;
}

Dog& Dog::operator=(Dog& cpy) {
	std::cout << "Dog: operator = called." << std::endl;
	if (this != &cpy)
	{
		this->_brain = cpy._brain;
		this->_type = cpy._type;
	}
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog: Destructor called." << std::endl;
}