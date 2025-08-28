/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:00:23 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/24 11:33:53 by dmazari          ###   ########.fr       */
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
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif