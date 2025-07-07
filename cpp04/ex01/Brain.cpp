/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:20:57 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 20:48:57 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(Brain& cpy) {
	std::cout << "Brain copy constructor called." << std::endl;
	int i = 0;

	while (i < 100)
	{
		_ideas[i] = cpy._ideas[i];
		i++;
	}
}

Brain& Brain::operator=(Brain& cpy) {
	std::cout << "Brain operator = called." << std::endl;
	if (this != &cpy)
	{
		int i = 0;
		while (i < 100)
		{
			_ideas[i] = cpy._ideas[i];
			i++;
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

void Brain::setIdeas(std::string idea) {
	int i = 0;
	while (i < 100 && !_ideas[i].empty())
		i++;
	if (i == 99)
		return ;
	_ideas[i] = idea;
}