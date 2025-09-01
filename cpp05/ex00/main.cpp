/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:13:13 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/30 15:30:21 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {
	try {
		Bureaucrat	first("Bob", 151);
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}

	try {
		Bureaucrat	second("Richard", -2);
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}


	try {
		Bureaucrat third("Philip", 1);
		std::cout << third << std::endl;
		third.incrementGrade();
		third.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}


	try {
		Bureaucrat fourth("Mathieu", 150);
		std::cout << fourth << std::endl;
		fourth.incrementGrade();
		std::cout << fourth << std::endl;
		fourth.decrementGrade();
		std::cout << fourth << std::endl;
		fourth.decrementGrade();
		std::cout << fourth << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& error) {
		std::cout << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& error) {
		std::cout << error.what() << std::endl;
	}


}