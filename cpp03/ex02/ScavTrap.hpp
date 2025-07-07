/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:49:34 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 12:33:05 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
	bool _guard;

	public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(ScavTrap& cpy);
	ScavTrap operator=(ScavTrap& cpy);

	void attack(std::string target);
	void guardGate();
};

#endif