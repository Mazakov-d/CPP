/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:10:28 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/30 00:34:43 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H__
# define ZOMBIE_H__

# include <string>

class Zombie {
	private:

		std::string name;

	public:

		Zombie();
		~Zombie();

		void announce (void);

		Zombie *newZombie(std::string name);
		void randomChump (std::string name);
};

#endif