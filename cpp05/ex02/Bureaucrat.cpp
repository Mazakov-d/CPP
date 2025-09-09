/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:33:12 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/06 13:44:53 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	_name = name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy) {
	_name = cpy.getName();
	_grade = cpy.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& cpy) {
	if (this != &cpy) {
		_name = cpy.getName();
		_grade = cpy.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	
}

std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
	return os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}

void	Bureaucrat::incrementGrade() {
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low !");
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}