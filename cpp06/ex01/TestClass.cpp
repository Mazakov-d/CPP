/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:10:35 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 17:11:55 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestClass.hpp"

TestClass::TestClass(): Serializer() {}

TestClass::TestClass(const TestClass & cpy): Serializer(cpy) {};

TestClass& TestClass::operator=(const TestClass& other) {
    (void)other;
    return *this;
}

TestClass::~TestClass() {}
