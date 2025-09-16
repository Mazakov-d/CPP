/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:45:20 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/16 22:16:21 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    _array = new T[0];
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
    _size = n;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T>::Array(const Array<T>& cpy) {
    _array = new T[cpy._size];
    _size = cpy._size;
    for (unsigned int i = 0; i < cpy._size; i++)
        _array[i] = cpy._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other)
    {
        delete[] this->_array;
        this->_array = new T[other._size];
        this->_size = other._size;
        for (unsigned int i = 0; i < other._size; i++)
            this->_array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int i) {
    if (i < 0 || static_cast<unsigned int>(i) >= this->_size)
        throw std::out_of_range("Index out of range");
    return this->_array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif