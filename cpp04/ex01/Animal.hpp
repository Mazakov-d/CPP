/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:00:23 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:31:15 by dorianmazar      ###   ########.fr       */
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
	Animal(Animal& cpy);
	Animal& operator=(Animal& cpy);
	~Animal();

	std::string getType() const;
	void makeSound() const;
};

#endif