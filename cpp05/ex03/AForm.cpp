/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:11:15 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/09 15:20:54 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Canonical Constructor/Destructor
AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(75), _gradeToExecute(75) {
	
}

AForm::~AForm() {
    
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _isSigned(false) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	_gradeToExecute = gradeToExecute;
	_gradeToSign = gradeToSign;
	_name = name;
}

AForm::AForm(const AForm& cpy) {
	_name = cpy.getName();
	_isSigned = cpy.isSigned();
	_gradeToExecute = cpy.getGradeToExecute();
	_gradeToSign = cpy.getGradeToSign();
}

AForm&	AForm::operator=(const AForm& cpy) {
	if (this != &cpy)
	{
		_name = cpy.getName();
		_isSigned = cpy.isSigned();
		_gradeToExecute = cpy.getGradeToExecute();
		_gradeToSign = cpy.getGradeToSign();
	}
	return *this;
}

//Getter functions
std::string	AForm::getName() const {
	return _name;
}

bool	AForm::isSigned() const {
	return _isSigned;
}

int	AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

int	AForm::getGradeToSign() const {
	return _gradeToSign;
}

//Class functions
void	AForm::beSigned(Bureaucrat& bureaucrat) {
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
const char*	AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high !");
}

const char*	AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low !");
}

const char* AForm::NotSigned::what(void) const throw() {
	return ("Form is not signed !");
}

//OStream operator << 
std::ostream& operator<<(std::ostream& o, AForm& form) {
	o << "The form " << form.getName() << " need a grade of " << form.getGradeToSign() << " to sign and a grade of ";
	o << form.getGradeToExecute() << " to execute, actually is " << (form.isSigned() ? "signed !" : "not signed !");
	return o;
}