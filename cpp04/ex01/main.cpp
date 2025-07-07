/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:56:27 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:56:55 by dorianmazar      ###   ########.fr       */
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
	
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	
	return 0;
}