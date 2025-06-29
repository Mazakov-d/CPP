/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:06:39 by mazakov           #+#    #+#             */
/*   Updated: 2025/06/29 14:28:58 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::retFirstName () {
	return (Contact::_firstName);
}

std::string Contact::retLastName () {
	return (Contact::_lastName);
}

std::string Contact::retNickname () {
	return (Contact::_nickname);
}

std::string Contact::retPhoneNumber () {
	return (Contact::_phoneNumber);
}

std::string Contact::retDarkestSecret () {
	return (Contact::_darkestSecret);
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
