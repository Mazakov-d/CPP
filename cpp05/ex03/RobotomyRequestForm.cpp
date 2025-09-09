/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:17:22 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/09 15:43:40 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
        AForm("RRF", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target):
        AForm(name, 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy):
	AForm(cpy), _target(cpy._target) {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}

const std::string RobotomyRequestForm::getTarget() {
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	static int i = 0;

	if (!this->isSigned())
		throw(NotSigned());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(GradeTooHighException());
	std::cout << "BRRRRRRRRRRRRRRRRRRRRRRZZZZZZZZZZZZZZZZZZZZZT" << std::endl;
	if (i % 2)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomization failled." << std::endl;
	i++;
}