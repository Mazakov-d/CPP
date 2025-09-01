/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:48:03 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/30 16:37:11 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Canonical Constructor/Destructor
Form::Form(): _name("default"), _isSigned(false), _gradeToSign(75), _gradeToExecute(75) {
	
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _isSigned(false) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	_gradeToExecute = gradeToExecute;
	_gradeToSign = gradeToSign;
	_name = name;
}

Form::Form(const Form& cpy) {
	_name = cpy.getName();
	_isSigned = cpy.isSigned();
	_gradeToExecute = cpy.getGradeToExecute();
	_gradeToSign = cpy.getGradeToSign();
}

Form	Form::operator=(const Form& cpy) {
	if (this != &cpy)
	{
		_name = cpy.getName();
		_isSigned = cpy.isSigned();
		_gradeToExecute = cpy.getGradeToExecute();
		_gradeToSign = cpy.getGradeToSign();
	}
	return *this;
}

Form::~Form() {
	
}

//Getter functions
std::string	Form::getName() const {
	return _name;
}

bool	Form::isSigned() const {
	return _isSigned;
}

int	Form::getGradeToExecute() const {
	return _gradeToExecute;
}

int	Form::getGradeToSign() const {
	return _gradeToSign;
}

//Class functions
void	Form::beSigned(Bureaucrat& bureaucrat) {
	int	gradeOfTheBureaucrat = bureaucrat.getGrade();
	int	gradeToSignForm = this->getGradeToSign();

	if (gradeOfTheBureaucrat > gradeToSignForm)
		throw GradeTooLowException();
	if (this->_isSigned == true)
	{
		std::cout << "From is already signed !" << std::endl;
		return ;
	}
	this->_isSigned = true; 
}

//Exception implementation
const char*	Form::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high !");
}

const char*	Form::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low !");
}


//OStream operator << 
std::ostream& operator<<(std::ostream& o, Form& form) {
	o << "The form " << form.getName() << " need a grade of " << form.getGradeToSign() << " to sign and a grade of ";
	o << form.getGradeToExecute() << " to execute, actually is " << (form.isSigned() ? "signed !" : "not signed !");
	return o;
}