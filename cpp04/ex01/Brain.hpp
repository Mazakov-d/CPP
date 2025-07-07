/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:16:25 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:38:42 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
	private:
	std::string _ideas[100];

	public:
	Brain();
	Brain(Brain& cpy);
	Brain& operator=(Brain& cpy);
	~Brain();

	void setIdeas(std::string idea);
};

#endif