/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:00:58 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:33:07 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
	private:
	Brain* _brain;

	public:
	Dog();
	Dog(const Dog& cpy);
	Dog& operator=(const Dog& cpy);
	void makeSound() const;
	~Dog();
};

#endif