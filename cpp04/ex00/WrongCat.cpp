/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:53:59 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:32:13 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Cat") {
	
}

WrongCat::WrongCat(WrongCat& cpy) {
	_type = cpy._type;
}

WrongCat& WrongCat::operator=(WrongCat& cpy) {
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

WrongCat::~WrongCat() {
	
}