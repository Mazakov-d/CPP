/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 00:20:04 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/18 00:22:38 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void separator(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n" << std::endl;
}

int main() {
    separator("Learning and Creating Materia");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    AMateria* unknown = src->createMateria("fire"); // should be null

    std::cout << "Created: " << (ice ? ice->getType() : "null") << std::endl;
    std::cout << "Created: " << (cure ? cure->getType() : "null") << std::endl;
    std::cout << "Created: " << (unknown ? unknown->getType() : "null") << " (should be null)" << std::endl;

    separator("Equipping and Using Materia");

    ICharacter* me = new Character("Dorian");
    ICharacter* bob = new Character("Bob");

    me->equip(ice);
    me->equip(cure);

    me->use(0, *bob); // use ice
    me->use(1, *bob); // use cure
    me->use(2, *bob); // nothing happens

    separator("Unequipping Materia");

    me->unequip(0); // unequip ice (should not delete!)
    me->use(0, *bob); // now slot is empty

    separator("Copy Character");

    Character* copy = new Character(*(Character*)me); // copy constructor
    copy->use(1, *bob); // should still be able to use cure
    copy->equip(new Ice());
    copy->use(0, *bob); // use new ice

    separator("Clean Up");

    delete bob;
    delete me;
    delete copy;
    delete src;

    // Don't forget to delete unequipped materias manually
    delete ice;
    delete cure;

    separator("Test Finished - Check with valgrind");
    return 0;
}
