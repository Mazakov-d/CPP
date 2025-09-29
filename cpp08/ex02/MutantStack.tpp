/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:51:47 by dmazari           #+#    #+#             */
/*   Updated: 2025/09/29 11:35:15 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack() {}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack& cpy): std::stack<T, C >(cpy) {
}

template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack& other) {
    if (this != &other)
        std::stack<T, C>::operator=(other);
    return *this;
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {}

template <typename T, typename C>
typename MutantStack<T, C>::iterator    MutantStack<T, C>::begin() {
    return this->c.begin();
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end() {
    return this->c.end();
}

#endif