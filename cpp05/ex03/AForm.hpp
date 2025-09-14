/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:11:29 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/09 15:22:46 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {
	private:
		std::string	_name;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;
	
	public:
		//Canonical Constructor/Destructor
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm& operator=(const AForm& cpy);
		AForm(const AForm& cpy);
		virtual ~AForm();

		//Getter functions
		std::string	getName() const;
		bool		isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

        virtual void execute(Bureaucrat const & executor) const = 0;

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
		class	NotSigned: public std::exception {
			public:
				virtual const char * what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, AForm& form);


#endif