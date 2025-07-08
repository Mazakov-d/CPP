/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:20:57 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:11:58 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain& cpy) {
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = cpy._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& cpy) {
	std::cout << "Brain operator = called." << std::endl;
	if (this != &cpy) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = cpy._ideas[i];
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
	if (i >= 100)
		return ;
	_ideas[i] = idea;
}