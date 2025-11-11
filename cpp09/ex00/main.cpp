/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:51:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/11/11 17:04:06 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// int checkExtension(const std::string &fileName) {
// 	size_t posExtension = fileName.find(".csv");

// 	if ((posExtension + 4) == fileName.size())
// 		return 0;
// 	return 1;
// }

int main(int ac, char **av) {
	BitcoinExchange ctx;

	if (ac != 2) {
		std::cerr << "Usage: ./btc [input]" << std::endl;
		return 1;
	}
	try {
		ctx.parseDataFile();
		ctx.executingConversion(av[1]);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}