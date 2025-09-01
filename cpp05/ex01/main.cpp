/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:13:13 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/30 16:41:58 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	try {
		Bureaucrat	bureaucratFirst("Bob", 151);
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Bureaucrat	bureaucratSecond("Richard", -2);
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}


	try {
		Bureaucrat	bureaucratThird("Philip", 1);
		std::cout << bureaucratThird << std::endl;
		bureaucratThird.incrementGrade();
		bureaucratThird.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}


	try {
		Bureaucrat	bureaucratFourth("Mathieu", 150);
		Form		firstForm;

		std::cout << firstForm << std::endl;
		bureaucratFourth.signForm(firstForm);
		std::cout << std::endl;
		while (bureaucratFourth.getGrade() > 76)
			bureaucratFourth.incrementGrade();
		bureaucratFourth.signForm(firstForm);
		std::cout << std::endl;
		bureaucratFourth.incrementGrade();
		bureaucratFourth.signForm(firstForm);
		std::cout << std::endl;
		std::cout << firstForm << std::endl;
		std::cout << std::endl;
		std::cout << bureaucratFourth << std::endl;
		bureaucratFourth.incrementGrade();
		std::cout << bureaucratFourth << std::endl;
		bureaucratFourth.decrementGrade();
		std::cout << bureaucratFourth << std::endl;
		bureaucratFourth.decrementGrade();
		std::cout << bureaucratFourth << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}


}