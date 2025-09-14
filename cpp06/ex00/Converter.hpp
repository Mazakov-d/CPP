/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:39:04 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/13 12:40:40 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include "ScalarConverter.hpp"

class Converter: public ScalarConverter {
    public:
        Converter();
        Converter(const Converter& cpy);
        Converter& operator=(const Converter& other);
        ~Converter();
};

#endif