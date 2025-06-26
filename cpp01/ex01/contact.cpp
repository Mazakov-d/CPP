/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:06:39 by mazakov           #+#    #+#             */
/*   Updated: 2025/06/26 16:20:50 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <contact.hpp>
#include <iostream>

Contact::Contact();

Contact::~Contact();

void Contact::displayFirstName () {
	std::cout << Contact::_firstName;
}

void Contact::displayLastName () {
	std::cout << Contact::_lastName;
}

void Contact::displayNickname () {
	std::cout << Contact::_nickname;
}

void Contact::displayPhoneNumber () {
	std::cout << Contact::_phoneNumber;
}

void Contact::displayDarkestSecret () {
	std::cout << Contact::_darkestSecret;
}

void Contact::addFirstName (const std::string newFirstName) {
	_firstName = newFirstName;
}

void Contact::addLastName (const std::string newLastName) {
	_lastName = newLastName;
}

void Contact::addNickname (const std::string newNickname) {
	_nickname = newNickname;
}

void Contact::addPhoneNumber (const std::string newPhoneNumber) {
	_phoneNumber = newPhoneNumber;
}

void Contact::addDarkestSecret (const std::string newDarkestSecret) {
	_darkestSecret = newDarkestSecret;
}
