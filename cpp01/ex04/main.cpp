/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:53:11 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/02 19:02:54 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av) {
	if (ac != 4)
	{
		std::cout << "Format: <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string fileName = std::string(av[1]) + ".replace";

	std::ifstream fileIn(av[1]);
	std::ofstream fileOut(fileName.c_str());

	if (!fileOut.is_open() || !fileIn.is_open())
	{
		std::cout << "Error opening file." << std::endl;
		return (1);
	}

	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string file;

	std::string content((std::istreambuf_iterator<char>(fileIn)),
					std::istreambuf_iterator<char>());

	size_t i = 0;
	while (i < content.length())
	{
		if (content.compare(i, s1.length(), s1) == 0) {
			file += s2;
			i += s1.length();
		}
		else
		{
			file += content[i];
			i++;
		}
	}
	fileOut << file;
	fileOut.close();
	fileIn.close();
}