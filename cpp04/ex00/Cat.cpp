/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:09:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:31:39 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(Cat& cpy) {
	_type = cpy._type;
	std::cout << "Cat: Copy constructor called: " << cpy._type << std::endl;
}

Cat& Cat::operator=(Cat& cpy) {
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called." << std::endl;
}