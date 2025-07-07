/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:51:16 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:27:27 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
	WrongCat();
	WrongCat(const WrongCat& cpy);
	WrongCat& operator=(const WrongCat& cpy);
	~WrongCat();
};

#endif