/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:47:15 by dmazari           #+#    #+#             */
/*   Updated: 2025/09/23 18:43:27 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>

template <typename T>
class MutantStack : public std::stack<T, std::vector<T> > {
    public:
        MutantStack();
        MutantStack(const MutantStack& cpy);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        typedef typename std::vector<T>::iterator iterator;
        
        iterator    begin();
        iterator    end();
};

# include "MutantStack.tpp" 

#endif