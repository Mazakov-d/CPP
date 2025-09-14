/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:02:38 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 17:13:23 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer& cpy) {
    (void)cpy;
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}

Serializer::~Serializer() {
}

uintptr_t   Serializer::serialize(Data* ptr) {
    uintptr_t   r;

    r = reinterpret_cast<uintptr_t>(ptr);
    return r;
}

Data*   Serializer::deserialize(uintptr_t raw) {
    Data*   r;

    r = reinterpret_cast<Data*>(raw);
    return r;
}
