/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:16:25 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/07 21:16:56 by dorianmazar      ###   ########.fr       */
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
	Brain(const Brain& cpy);
	Brain& operator=(const Brain& cpy);
	~Brain();

	void setIdeas(std::string idea);
};

#endif