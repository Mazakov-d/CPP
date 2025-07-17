/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:09:24 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/17 22:39:47 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {
	private:

	public:
	Ice();
	~Ice();
	Ice(const Ice& cpy);
	Ice& operator=(const Ice& other);
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif