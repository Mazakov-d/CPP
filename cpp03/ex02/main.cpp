/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:46:36 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/24 11:15:01 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap a("Mark");
	ScavTrap b("Francis");
	a.attack("Francis");
	b.takeDamage(20);
	ClapTrap c("Rick");
	c = a;
	c.attack("Francis");
	FragTrap d("paul");
	d.highFivesGuys();
}