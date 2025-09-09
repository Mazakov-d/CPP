/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:17:33 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/09 15:43:21 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
        AForm("SCF", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target):
        AForm(name, 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& cpy):
	AForm(cpy), _target(cpy._target) {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

const std::string ShrubberyCreationForm::getTarget() {
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->isSigned())
		throw(NotSigned());
	if (executor.getGrade() > this->getGradeToExecute())
		throw(GradeTooLowException());
	std::string fileName = _target + "_shrubbery";
	std::fstream fs;
	fs.open(fileName.c_str(), std::fstream::out | std::fstream::trunc);
	if (fs.is_open())
	{
		fs << "                *\n";
		fs << "               /o\\\n";
		fs << "              /+++\\\n";
		fs << "             /o+++o\\\n";
		fs << "            /++o+++o+\\\n";
		fs << "           /o+++o+++o+\\\n";
		fs << "          /+++o+++o+++o\\\n";
		fs << "         /o+++o+++o+++o+\\\n";
		fs << "        /++o+++o+++o+++o+\\\n";
		fs << "       /o+++o+++o+++o+++o+\\\n";
		fs << "      /+++o+++o+++o+++o+++o\\\n";
		fs << "     /o+++o+++o+++o+++o+++o+\\\n";
		fs << "    /++++++++++++++++++++++++\\\n";
		fs << "               |||||\n";
		fs << "               |||||\n";
		fs.close();
	}
	else
	{
		std::cout << "Error opening file" << std::endl;;
	}
}