/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:17:10 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/09 15:44:02 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
        AForm("PPF", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target): 
        AForm(name, 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy): 
	AForm(cpy), _target(cpy._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}

const std::string PresidentialPardonForm::getTarget() {
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw(NotSigned());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(GradeTooLowException());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}