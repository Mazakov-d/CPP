/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:55:02 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 17:12:47 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

struct Data {
    int       i;
    char      c;
    double    d;
    void*     ptr;
};

class Serializer {
    public:
        Serializer();
        Serializer(const Serializer& cpy);
        Serializer& operator=(const Serializer& other);
        virtual ~Serializer() = 0;    

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif