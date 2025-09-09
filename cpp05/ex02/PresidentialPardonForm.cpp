/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:17:10 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/06 13:50:50 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
        AForm("PPF", 25, 5), _target(target) {
    
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) {
    
}