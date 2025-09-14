/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:33:32 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/09/09 15:22:32 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class	Bureaucrat {
	private:
		std::string	_name;
		int			_grade;

	public:
	
		//Canonical form
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& cpy);
		Bureaucrat&	operator=(const Bureaucrat &cpy);
		~Bureaucrat();

		//Getter functions
		std::string	getName() const;
		int			getGrade() const;

		//Incrementing/Decrementing funcionts
		void		incrementGrade();
		void		decrementGrade();

		//Form function
		void	signForm(AForm& form);
		void	executeForm(AForm const & form);

		// Execption class
		class	GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif