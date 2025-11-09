/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:51:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/11/07 09:04:31 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int checkExtension(const std::string& fileName) {
    size_t  posExtension = fileName.find(".csv");

    
    if ((posExtension + 4) == fileName.size())
        return 0;
    return 1;
}

int main(int ac, char **av) {
    BitcoinExchange ctx;

    if (ac != 2)
    {
        std::cerr << "Usage: ./btc [data.csv]" << std::endl;
        return 1;
    }
    if (checkExtension(av[1]))
    {
        std::cerr << "File should be .csv." << std::endl;
        return 1;
    }
    try {
        std::string content = ctx.parseDataFile(av[1]);
        std::cout << content << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}