/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:43:57 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/19 18:43:40 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int N): _capacity(N), _size(0) {

    _ar.reserve(N);
}


Span::~Span() {}






Span::Span(const Span& cpy): _capacity(cpy._capacity), _size(0) {
    _ar.reserve(_capacity);
    for (std::vector<int>::const_iterator it = cpy._ar.begin(); it < cpy._ar.end(); it++)
    {
        _ar.push_back(*it);
        _size++;
    }
}

Span& Span::operator=(const Span& other) {
    if (this != &other)
    {
        this->_ar.erase(_ar.begin(), _ar.end());
        this->_ar.reserve(other._capacity);
        this->_capacity = other._capacity;
        this->_size = 0;
        for (std::vector<int>::const_iterator it = other._ar.begin(); it < other._ar.end(); it++)
        {
            this->_size++;
            this->_ar.push_back(*it);
        }
    }
    return *this;
}






void    Span::addNumber(int n) {
    if (_capacity <= _size)
        throw(OverSize());
    _ar.push_back(n);
    _size++;
}

unsigned int Span::shortestSpan() {
    unsigned int    *save = NULL;
    unsigned int    span;

    if (_size == 0 || _size == 1)
        throw(NotEnoughMembers());
    for (std::vector<int>::const_iterator it = _ar.begin(); it < _ar.end(); it++) {
        for (std::vector<int>::const_iterator jt = it + 1; jt < _ar.end(); jt++) {
            if (!save)
            {
                span = abs(*it - *jt);
                save = &span;
            }
            else
            {
                if (span > abs(*it - *jt))
                    span = abs(*it - *jt);
            }
        }
    }
    return span;
}

unsigned int Span::longestSpan() {
    unsigned int    *save = NULL;
    unsigned int    span;

    if (_size == 0 || _size == 1)
        throw(NotEnoughMembers());
    for (std::vector<int>::const_iterator it = _ar.begin(); it < _ar.end(); it++) {
        for (std::vector<int>::const_iterator jt = it + 1; jt < _ar.end(); jt++) {
            if (!save)
            {
                span = abs(*it - *jt);
                save = &span;
            }
            else
            {
                if (span < abs(*it - *jt))
                    span = abs(*it - *jt);
            }
        }
    }
    return span;
}



void    Span::fill_array_in_capacity() {
    while (_size < _capacity)
    {
        _ar.push_back(rand() % 11072001);
        _size++;
    }
}




const char* Span::NotEnoughMembers::what() const throw() {
    return "Not enough members in the array to make this operation.";
}

const char* Span::OverSize::what() const throw() {
    return "The capacity of the vector is full.";
}