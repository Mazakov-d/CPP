/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:42:40 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/16 22:17:26 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T> 
class Array {
    private:
        T*              _array;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array<T>& cpy);
        Array& operator=(const Array<T>& other);

        T& operator[](int i);
        unsigned int size() const;
};

# include "Array.tpp"

#endif