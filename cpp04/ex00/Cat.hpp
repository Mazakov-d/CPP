/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:00:47 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:29:32 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal {
	public:
	Cat();
	Cat(const Cat& cpy);
	Cat& operator=(const Cat& cpy);
	void makeSound() const ;
	~Cat();
};

#endif