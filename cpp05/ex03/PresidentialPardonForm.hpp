/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:16:55 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/09 15:42:28 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private :
        std::string _target;

    public :
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(std::string name, std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& cpy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

		const std::string getTarget();

        void execute(Bureaucrat const & executor) const;
} ;

#endif