/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:40:51 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 23:13:34 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	
}

Harl::~Harl() {
	
}

void Harl::debug( void ) {
	std::cout << " [ DEBUG ] " << std::endl;
	std::cout << "I think it's unfair that everyone says I finish too quickly during meetings. " << std::endl;
	std::cout << " That's what she said!" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void ) {
	std::cout << " [ INFO ] " << std::endl;
	std::cout << "I love how I can make any situation awkward just by being myself." << std::endl;
	std::cout << " How you doin'?" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void ) {
	std::cout << " [ WARNING ] " << std::endl;
	std::cout << "I can't understand why people don't appreciate my genius. " << std::endl;
	std::cout << " Bazinga!" << std::endl;
	std::cout << std::endl;
}

void Harl::error( void ) {
	std::cout << " [ ERROR ] " << std::endl;
	std::cout << "This is outrageous! Nobody puts Baby in a corner! Wait, wrong situation..." << std::endl;
	std::cout << std::endl;
}

void Harl::complain( std::string level) {
	void (Harl::*function[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string functionsNames[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (functionsNames[i] ==level) {
			(this->*function[i])();
		}
	}
}