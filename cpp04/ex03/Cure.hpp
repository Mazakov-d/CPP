/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:09:07 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/17 22:40:01 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	private:

	public:
	Cure();
	~Cure();
	Cure(const Cure& cpy);
	Cure& operator=(const Cure& other);
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif