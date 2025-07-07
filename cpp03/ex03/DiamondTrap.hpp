/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:47:34 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 14:13:28 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

	public:
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap& cpy);
	DiamondTrap operator=(DiamondTrap& cpy);
	~DiamondTrap();

	void whoAmI();
};

#endif