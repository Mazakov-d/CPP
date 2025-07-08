/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:56:27 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 22:03:23 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
	Animal* animals[] = {new Cat(),
		new Dog(),
		new Cat(),
		new Dog()};

	std::cout << animals[0]->getType();
	animals[0]->makeSound();

	Cat* cpy = new Cat(*(Cat*)animals[0]);

	cpy->makeSound();

	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	
	cpy->makeSound();
	delete cpy;
	return 0;
}