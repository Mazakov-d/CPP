/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:47:50 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/06/29 14:34:56 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phone_book.hpp"
#include <iostream>

int main()
{
	std::string input;
	PhoneBook myPhoneBook;

	std::cout << "Welcome to the PhoneBook !" << std::endl;
	while (1)
	{
		std::cout << "What do you want to do: ";
		std::cin >> input;
		if (std::cin.eof())
		{
			std::cout << "\nLet's close the PhoneBook" << std::endl;
			return (1);
		}
		if (input == "EXIT")
		{
			std::cout << "\nLet's close the PhoneBook" << std::endl;
			return (0);
		}
		else if (input == "ADD")
		{
			if (myPhoneBook.addContact())
			{
				std::cout << "\nLet's close the PhoneBook." << std::endl;
				return (1);
			}
		}
		else if (input == "SEARCH")
		{
			if (myPhoneBook.searchContact())
			{
				std::cout << "\nLet's close the PhoneBook." <<std::endl;
				return (1);
			}
			
		}
		else
			std::cout << "Don't know this command, try again." << std::endl;
		input.clear();
	}
	return (0);
}
