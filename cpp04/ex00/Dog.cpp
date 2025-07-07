/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:17:03 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:31:47 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog: Default constructor is called." << std::endl;
}

Dog::Dog(Dog& cpy) {
	_type = cpy._type;
	std::cout << "Dog: Copy constructor called." << std::endl;
}

Dog& Dog::operator=(Dog& cpy) {
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called." << std::endl;
}