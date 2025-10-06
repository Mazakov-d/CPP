/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:14:01 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/19 18:48:01 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try {
        Span sp = Span(5);
        try {
            sp.longestSpan();
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            sp.shortestSpan();
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << std::endl;
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        try {
            sp.addNumber(2424);
        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Span sp_b = Span(10000);     
        sp_b.fill_array_in_capacity();
        try {
            sp_b.addNumber(23);
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    
        std::cout << sp_b.shortestSpan() << std::endl;
        std::cout << sp_b.longestSpan() << std::endl << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}