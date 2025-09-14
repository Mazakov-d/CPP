/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:10:38 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/13 13:38:43 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define UNKNOWN 4

class ScalarConverter {
    public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cpy);
    ScalarConverter& operator=(const ScalarConverter& other);
    virtual ~ScalarConverter() = 0;
    
    static void convert(const char* str);
};

#endif