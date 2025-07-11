/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:36 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 13:07:18 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ClapTrap a("Bob");
	ClapTrap b(a);
	ClapTrap c("Marie");
	c.beRepaired(10);
	c = b;

	ScavTrap t("salut");
	t.attack("Bob");
	t.attack("Bob");

	ScavTrap o(t);
	t.guardGate();
	t.guardGate();
	o.attack("filou");
	ScavTrap last("mark");
	last.beRepaired(4);
	last = o;
	last.takeDamage(12);
}