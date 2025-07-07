/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:10:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 13:55:43 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
	FragTrap(std::string name);
	FragTrap(FragTrap& cpy);
	FragTrap operator=(FragTrap& cpy);
	~FragTrap();

	void highFivesGuys(void);
};

#endif