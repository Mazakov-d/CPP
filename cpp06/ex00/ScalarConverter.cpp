/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:12:17 by mazakov           #+#    #+#             */
/*   Updated: 2025/09/14 15:51:39 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstring>
#include <cerrno>
#include <cfloat>
#include <limits>
#include <climits>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) {
    (void)cpy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}


bool    is_char(const char* str)
{
    if (std::strlen(str) == 1)
        if (str[0] >= 33 && str[1] <= 126)
            return true;
    return false;
}

bool    is_int(const char* str)
{
    for (size_t i = 0; i < std::strlen(str); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool    is_double(const char* str)
{
    int flag_dot = 0;
    
    for (size_t i = 0; i < std::strlen(str); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return (false);
        if (str[i] == '.' && flag_dot > 0)
            return (false);
        if (str[i] == '.')    
            flag_dot++;
    }
    if (flag_dot == 0)
        return (false);
    return (true);
}

bool    is_float(const char* str)
{
    int flag_dot = 0;
    int flag_f   = 0;

    for (size_t i = 0; i < std::strlen(str); i++)
    {
        if (!isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
            return (false);
        if (str[i] == 'f' && flag_f > 0)
            return (false);
        if (str[i] == '.' && flag_dot > 0)
            return (false);
        if (str[i] == 'f')
            flag_f++;
        if (str[i] == '.')
            flag_dot++;
    }
    if (flag_dot == 0 || flag_f == 0)
        return (false);
    return (true);
}

int check_type(const char* str)
{
    if (is_char(str))
        return (CHAR);
    if (is_int(str))
        return (INT);
    if (is_double(str))
        return (DOUBLE);
    if (is_float(str))
        return (FLOAT);
    return (UNKNOWN);
}

void    char_convert(double d) {
    std::cout << "char: ";
    if (d < 33 || d > 126)
        std::cout << "Non displayable." << std::endl;
    else
    {
        char c = static_cast<char>(d); 
        std::cout << c << std::endl;
    }
}

void    int_convert(double d)
{
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
    {
        int i = static_cast<int>(d);
        std::cout << "int: " << i << std::endl;
    }
}

void    float_convert(double d)
{
    if (d > FLT_MAX)
        std::cout << "float: +inff" << std::endl;
    else if (d < FLT_MIN)
        std::cout << "float: -inff" << std::endl;
    else
    {
        float   f = static_cast<float>(d);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void    double_convert(long double ld)
{
    if (ld > DBL_MAX)
        std::cout << "double: +inf" << std::endl;
    else if (ld < -DBL_MAX)
        std::cout << "double: -inf" << std::endl;
    else
    {
        double  d = static_cast<double>(ld);
        std::cout << "double: " << d << std::endl;
    }
}

void    cast_from_char(const char* str)
{
    char_convert(str[0]);
    int i;
    float   f;
    double  d;

    i = static_cast<int>(str[0]);
    f = static_cast<float>(str[0]);
    d = static_cast<double>(str[0]);
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    not_displayable()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void    cast_from_n(const char* str)
{
    errno = 0;
    long double  ld;

    ld = strtold(str, NULL);
    if (errno == ERANGE)
        return (not_displayable());
    char_convert(ld);
    int_convert(ld);
    float_convert(ld);
    double_convert(ld);
}

void ScalarConverter::convert(const char* str) {
    int type;

    std::cout << std::fixed << std::setprecision(1);
    type = check_type(str);
    if (type == UNKNOWN)
        return (not_displayable());
    if (type == CHAR)
        return (cast_from_char(str));
    else
        return (cast_from_n(str));
}