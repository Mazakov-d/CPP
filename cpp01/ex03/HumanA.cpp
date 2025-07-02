/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:16:33 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 18:20:55 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(&weapon), _name(name) {
}

HumanA::~HumanA() {
	
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}