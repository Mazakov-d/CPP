/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:40:45 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/13 14:34:36 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(): ScalarConverter() {}

Converter::Converter(const Converter& cpy): ScalarConverter() {
    (void)cpy;
}

Converter& Converter::operator=(const Converter& other) {
    (void)other;
    return *this;
}

Converter::~Converter() {}