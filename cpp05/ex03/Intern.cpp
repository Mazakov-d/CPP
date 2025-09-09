/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:38:02 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/09 16:06:07 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	
}

Intern::Intern(Intern const& cpy) {
	(void)cpy;
}

Intern&	Intern::operator=(Intern const& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {

}

AForm*	Intern::makeForm(std::string name, std::string target) {
	int	i;
	int	form = -1;
	std::string	forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	for (i = 0; i < 3; i++) {
		if (forms[i] == name)
			form = i;
	}
	switch (form) {
	case 0:
		return (new RobotomyRequestForm(name, target));
	case 1:
		return (new PresidentialPardonForm(name, target));
	case 2:
		return (new ShrubberyCreationForm(name, target));
	default:
		std::cout << "Dont know this request\n";
		return nullptr;
}
}