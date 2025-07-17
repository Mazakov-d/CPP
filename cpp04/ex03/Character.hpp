/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:19:41 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/18 00:03:53 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "vector"

class Character: public ICharacter {
	private:
	std::string _name;
	int _equipement;
	AMateria* _materias[4];
	std::vector<AMateria*> _trash;
	int _trashedI;

	public:
	Character(std::string name);
	~Character();
	Character(const Character& cpy);
	Character& operator=(const Character& other);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif