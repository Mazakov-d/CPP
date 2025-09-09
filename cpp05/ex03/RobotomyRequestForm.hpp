/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:17:26 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/09 15:42:41 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private :
        std::string _target;

    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(std::string name, std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& cpy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

		const std::string getTarget();

        void execute(Bureaucrat const & executor) const;

    } ;

#endif