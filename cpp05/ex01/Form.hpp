/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:47:47 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/30 16:27:28 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
	private:
		std::string	_name;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;
	
	public:
		//Canonical Constructor/Destructor
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form operator=(const Form& cpy);
		Form(const Form& cpy);
		~Form();

		//Getter functions
		std::string	getName() const;
		bool		isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		//Class functions
		void		beSigned(Bureaucrat& bureaucrat);

		//Exceptions classes
		class	GradeTooHighException: public std::exception {
			public:
				virtual const char * what(void) const throw();
		};
		class	GradeTooLowException: public std::exception {
			public:
				virtual const char * what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, Form& form);


#endif