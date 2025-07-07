/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:56:27 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:06:47 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int main()
{
const WrongAnimal* k = new WrongCat();
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* l = new WrongAnimal();
std::cout << j->getType() << " " << std::endl;
j->makeSound();
std::cout << std::endl << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
std::cout << std::endl << k->getType() << " " << std::endl;
k->makeSound();
std::cout << std::endl << meta->getType() << std::endl;
meta->makeSound();
std::cout << std::endl << l->getType() << std::endl;
l->makeSound();

delete l;
l = k;
std::cout << std::endl << l->getType() << std::endl;
l->makeSound();


delete k;
delete meta;
delete j;
delete i;
return 0;
}