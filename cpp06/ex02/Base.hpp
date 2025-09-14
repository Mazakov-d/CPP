/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:03:01 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 20:49:04 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <ctime>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <functional>


class Base {
    protected:
        std::string _name;
    public:
        Base();
        Base(std::string name);
        virtual ~Base() = 0;
        
        Base*   generate(void);
        void    identify(Base* p);
        void    identify(Base& p);
};

#endif