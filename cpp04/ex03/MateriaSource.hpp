/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:43:19 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/18 00:04:25 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
	AMateria* _materias[4];


	public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& cpy);
	MateriaSource& operator=(const MateriaSource& other);
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const& type);
};

#endif