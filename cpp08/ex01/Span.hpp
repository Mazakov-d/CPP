/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:29:55 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/19 18:41:40 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <cstdlib>

class Span {
    private:
    unsigned int     _capacity;
    unsigned int     _size;
        std::vector<int> _ar;
    public:
        Span(unsigned int N);
        virtual ~Span();
        Span(const Span& cpy);
        Span& operator=(const Span& other);

        void addNumber(int);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        void    fill_array_in_capacity();

        class OverSize: public std::exception {
            public:
                const char* what() const throw();
        };
        class NotEnoughMembers: public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif