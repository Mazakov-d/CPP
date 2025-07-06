/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:36 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/05 14:01:44 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Bob");
	ClapTrap b(a);

	b.attack("Bob");
	b.beRepaired(10);
	b.beRepaired(10);
	b.takeDamage(20);
	b.beRepaired(10);
	b.beRepaired(10);
	b.takeDamage(20);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	b.beRepaired(10);
	ClapTrap c("Marie");
	c = b;
	c.beRepaired(10);
}