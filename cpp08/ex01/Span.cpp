/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:43:57 by mazakov           #+#    #+#             */
/*   Updated: 2025/10/28 01:05:54 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <limits>
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
	if (_size < 2)
		throw (NotEnoughMembers());
	std::sort(_ar.begin(), _ar.end());
	int	save = std::numeric_limits<int>::max();
	int	diff;

	for (size_t i = 0; i < _size; i++) {
		std::cout << "Array sorted: "<< _ar[i] << std::endl;
	}
	for (size_t i = 1; i < _size - 1; i++) {
		diff = _ar[i] - _ar[i - 1];
		if (diff < save)
			save = diff;
	}
	return save;
}

unsigned int Span::longestSpan() {
	std::vector<int>::const_iterator itMin = std::min_element(_ar.begin(), _ar.end());
	std::vector<int>::const_iterator itMax = std::max_element(_ar.begin(), _ar.end());

	if (itMin == _ar.end() || itMin == itMax)
		throw (NotEnoughMembers());
	return abs(*itMax - *itMin);
}

void    Span::fill_array_in_capacity() {
    while (_size < _capacity)
    {
		int n = rand() % 1234;
        _ar.push_back(n);
		std::cout << "Fill function: " << n <<std::endl;
        _size++;
    }
}

const char* Span::NotEnoughMembers::what() const throw() {
    return "Not enough members in the array to make this operation.";
}

const char* Span::OverSize::what() const throw() {
    return "The capacity of the vector is full.";
}