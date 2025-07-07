/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:53:59 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:21:55 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Cat") {
	
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal(cpy) {
	std::cout << "WrongCat: Copy constructor called: " << _type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& cpy) {
	std::cout << "WrongCat: Operator '=' called: " << cpy._type << std::endl;
	if (this != &cpy)
		WrongAnimal::operator=(cpy);
	return *this;
}

WrongCat::~WrongCat() {
	
}