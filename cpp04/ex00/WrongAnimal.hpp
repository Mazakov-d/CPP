/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:43:32 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:32:08 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {
	protected:
	std::string _type;

	public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal& cpy);
	WrongAnimal& operator=(WrongAnimal& cpy);
	~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif