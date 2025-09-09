/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:13:13 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/09 16:05:21 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main() {
	// try {
	// 	Bureaucrat	bureaucratFirst("Bob", 151);
	// }
	// catch (Bureaucrat::GradeTooHighException& error) {
	// 	std::cout << error.what() << std::endl;
	// }
	// catch (Bureaucrat::GradeTooLowException& error) {
	// 	std::cout << error.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat	bureaucratSecond("Richard", -2);
	// }
	// catch (Bureaucrat::GradeTooHighException& error) {
	// 	std::cout << error.what() << std::endl;
	// }
	// catch (Bureaucrat::GradeTooLowException& error) {
	// 	std::cout << error.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat	bureaucratThird("Philip", 1);
	// 	std::cout << bureaucratThird << std::endl;
	// 	bureaucratThird.incrementGrade();
	// 	bureaucratThird.decrementGrade();
	// }
	// catch (Bureaucrat::GradeTooHighException& error) {
	// 	std::cout << error.what() << std::endl;
	// }
	// catch (Bureaucrat::GradeTooLowException& error) {
	// 	std::cout << error.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat	bureaucratFourth("Mathieu", 150);
	// 	Bureaucrat leBoss("Boss", 1);
	// 	ShrubberyCreationForm	shrubberyForm("Tree");
	// 	PresidentialPardonForm pardonForm("YO");
	// 	RobotomyRequestForm robotForm("tww");

	// 	leBoss.signForm(shrubberyForm);
	// 	leBoss.signForm(pardonForm);
	// 	leBoss.executeForm(robotForm);
	// 	leBoss.signForm(robotForm);
	// 	leBoss.executeForm(shrubberyForm);
	// 	leBoss.executeForm(robotForm);
	// 	leBoss.executeForm(robotForm);
	// 	leBoss.executeForm(robotForm);
	// 	leBoss.executeForm(robotForm);
	// 	leBoss.executeForm(pardonForm);
	// }
	// catch(std::exception &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << rrf->getName();
	}

}