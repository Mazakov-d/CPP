/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:31:55 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 15:36:28 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    int              i;
    ScalarConverter* a = new Converter;

    for (i = 1; i < ac; i++)
    {
        a->convert(av[i]);
        if (i < ac - 1)
            std::cout << std::endl;
    }
    delete a;
}