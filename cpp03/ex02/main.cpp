/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:36 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 13:34:52 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap a;
	ScavTrap b("Francis");
	a.attack("Francis");
	b.takeDamage(20);
	ClapTrap c("Rick");
	c = a;
	c.attack("Francis");
	FragTrap d;
	d.highFivesGuys();
}