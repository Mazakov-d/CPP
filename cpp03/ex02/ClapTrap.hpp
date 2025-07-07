/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:14:14 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 13:55:34 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap {
	protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

	public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap& cpy);
	ClapTrap& operator=(const ClapTrap& cpy);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif