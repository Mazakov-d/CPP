/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:28:35 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/07/02 18:55:23 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"
#include "contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() : _contactCount(0), _oldestContact(0) {
}

PhoneBook::~PhoneBook() {
	
}

void displayColumn(std::string text)
{
	int i = 0;
	int flag = 0;

	while (i < 10)
	{
		if (!flag && !text[i])
			flag = 1;
		if (!flag && text[i])
			std::cout << text[i];
		if (flag)
			std::cout << " ";
		i++;
	}
}

void displayIndex(int index)
{
	int i = 1;

	std::cout << index;
	while (i < 10)
	{
		std::cout << " ";
		i++;
	}
}

void displayLine(std::string first, std::string second, std::string third, std::string fourth)
{
	displayColumn(first);
	std::cout << "|";
	displayColumn(second);
	std::cout << "|";
	displayColumn(third);
	std::cout << "|";
	displayColumn(fourth);
	std::cout << std::endl;
}

void displayLineWIndex(int index, std::string second, std::string third, std::string fourth) {
	displayIndex(index);
	std::cout << "|";
	displayColumn(second);
	std::cout << "|";
	displayColumn(third);
	std::cout << "|";
	displayColumn(fourth);
	std::cout << std::endl;
}


int PhoneBook::addContact() {
	std::string input;
	size_t i = 0;
	int flag = 0;
	int currentIndex = _contactCount;

	if (_contactCount >= 8) {
		currentIndex = _oldestContact;
		_oldestContact = (_oldestContact + 1) % 8;
	}

	do {
		std::cout << "First Name: ";
		std::cin >> input;
		if (std::cin.eof())
			return (1);
		if (input.empty()) {
			std::cout << "Invalid First Name." << std::endl;
		}
	} while (input.empty());
	_contacts[currentIndex].addFirstName(input);

	do {
		std::cout << "Last Name: ";
		std::cin >> input;
		if (std::cin.eof())
			return (1);
		if (input.empty()) {
			std::cout << "Invalid Last Name." << std::endl;
		}
	} while (input.empty());
	_contacts[currentIndex].addLastName(input);

	do {
		std::cout << "Nickname: ";
		std::cin >> input;
		if (std::cin.eof())
			return (1);
		if (input.empty()) {
			std::cout << "Invalid Nickname." << std::endl;
		}
	} while (input.empty());
	_contacts[currentIndex].addNickname(input);

	do {
		std::cout << "Phone Number: ";
		std::cin >> input;
		if (std::cin.eof())
			return (1);
		i = 0;
		flag = 0;
		while (i < input.length()) {
			if (!isdigit(input[i]))
			{
				std::cout << "Invalid Phone Number: only digits accepted." << std::endl;
				flag = 1;
				break ;
			}
			i++;
		}
	} while (input.empty() || flag);
	_contacts[currentIndex].addPhoneNumber(input);

	do {
		std::cout << "Darkest Secret: ";
		std::cin >> input;
		if (std::cin.eof())
			return (1);
		if (input.empty()) {
			std::cout << "Don't be shy." << std::endl;
		}
	} while (input.empty());
	_contacts[currentIndex].addDarkestSecret(input);
	_contactCount++;
	return (0);
}


int PhoneBook::searchContact() {
	int i = 0;
	int index;
	std::string input;

	if (_contactCount == 0 && _oldestContact == 0)
	{
		std::cout << "No contact for the moment." << std::endl;
		return (0);
	}
	while (i < _contactCount && i < 8)
	{
		if (i == 0)
			displayLine("Index", "First Name", "Last Name", "Nickname");
		displayLineWIndex((i + 1),
				_contacts[i].retFirstName(),
				_contacts[i].retLastName(),
				_contacts[i].retNickname());
		i++;
	}
	while (1)
	{
		std::cout << "You want informations from the index: ";
		std::cin >> input;
		if (std::cin.eof())
			return (1);
		if (input.length() > 1 || !isdigit(input[0]) || input[0] == '0')
			std::cout << "Invalid index." << std::endl;
		else
		{
			index = (input[0] - '0') - 1;
			if (_contactCount > 8 && index > 8)
				std::cout << "The index max is 8." << std::endl;
			else if (index >= _contactCount)
				std:: cout << "The index max is " << _contactCount << std::endl;
			else
				break ;
		}
	}
	index = (input[0] - '0') - 1;
	std::cout << "First Name: " << _contacts[index].retFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].retLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].retNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].retPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].retDarkestSecret() << std::endl;
	return (0);
}
