/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:00:23 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 22:01:39 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
	protected:
	std::string _type;

	public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& cpy);
	Animal& operator=(const Animal& cpy);
	virtual ~Animal() = 0;

	std::string getType() const;
	virtual void makeSound() const;
};

#endif