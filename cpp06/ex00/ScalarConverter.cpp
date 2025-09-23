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
#include <cfloat>
#include <limits>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>

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

template<typename T>
T safeConvert(const char* str) {
    std::stringstream ss(str);
    T result;
    ss >> result;
    
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("impossible");
    }
    
    return result;
}

bool    is_char(const char* str)
{
    if (std::strlen(str) == 1)
        if (str[0] >= 33 && str[1] <= 126)
            return true;
    return false;
}

bool    is_int(const char* str)
{
    size_t i = 0;

    if (str && str[0] == '-')
        i++;
    for (size_t j = i; j < std::strlen(str); j++)
    {
        if (!isdigit(str[j]))
            return false;
    }
    return true;
}

bool    is_double(const char* str)
{
    int flag_dot = 0;
    size_t i = 0;

    if (str && str[0] == '-')
        i++;
    for (size_t j = i; j < std::strlen(str); j++)
    {
        if (!isdigit(str[j]) && str[j] != '.')
            return (false);
        if (str[j] == '.' && flag_dot > 0)
            return (false);
        if (str[j] == '.')    
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
    size_t i = 0;

    if (str && str[0] == '-')
        i++;
    for (size_t j = i; j < std::strlen(str); j++)
    {
        if (!isdigit(str[j]) && str[j] != 'f' && str[j] != '.')
            return (false);
        if (str[j] == 'f' && flag_f > 0)
            return (false);
        if (str[j] == '.' && flag_dot > 0)
            return (false);
        if (str[j] == 'f')
            flag_f++;
        if (str[j] == '.')
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

void    char_convert_from_double(double d) {
    std::cout << "char: ";
    if (d < 33 || d > 126)
        std::cout << "Non displayable." << std::endl;
    else
    {
        char c = static_cast<char>(d); 
        std::cout << c << std::endl;
    }
}

void    char_convert(int i)
{
    std::cout << "char: ";
    if (i < 33 || i > 126)
        std::cout << "Non displayable." << std::endl;
    else
    {
        char c = static_cast<char>(i); 
        std::cout << c << std::endl;
    }
}

void    char_convert_from_float(float f)
{
    std::cout << "char: ";
    if (f < 33 || f > 126)
        std::cout << "Non displayable." << std::endl;
    else
    {
        char c = static_cast<char>(f); 
        std::cout << c << std::endl;
    }
}

void    int_convert_from_float(float f)
{
    if (f > 2147483648 || f < (-2147483647.0))
        std::cout << "int: impossible" << std::endl;
    else
    {
        int i = static_cast<int>(f);
        std::cout << "int: " << i << std::endl;
    }
}

void    int_convert_from_double(double d)
{
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
    {
        int i = static_cast<int>(d);
        std::cout << "int: " << i << std::endl;
    }
}


void    float_convert_from_double(double d)
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

void    cast_from_int(const char* str)
{
    long i;

    try {
        i = safeConvert<int>(str);
    }
    catch (std::exception &e) {
        return (not_displayable());
    }
    if (i > INT_MAX || i < INT_MIN)
    {
        std::cout << "here" << std::endl;
        return (not_displayable());
    }
    char_convert(i);
    std::cout << "int: " << i << std::endl;
    double  d = static_cast<double>(i);
    std::cout << "double: " << d << std::endl;
    float   f = static_cast<float>(i);
    std::cout << "float: " << f << "f" << std::endl;
}

void    cast_from_flt(const char* str)
{
    float   f;
    char* s = new char[strlen(str) + 1];

    strcpy(s, str);
    s[strlen(s) - 1] = 0;
    try {
        f = safeConvert<float>(s);
    }
    catch (std::exception &e) {
        delete[] s;
        return (not_displayable());
    }
    char_convert_from_float(f);
    int_convert_from_float(f);
    std::cout << "float: " << f << "f" << std::endl;
    double  d = static_cast<double>(f);
    std::cout << "double: " << d << std::endl;
    delete[] s;
}

void    cast_from_d(const char* str)
{
    double  d;

    try {
        d = safeConvert<double>(str);
    }
    catch (std::exception &e) {
        return (not_displayable());
    }
    char_convert_from_double(d);
    int_convert_from_double(d);
    float_convert_from_double(d);
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const char* str) {
    int type;

    std::cout << std::fixed << std::setprecision(1);
    type = check_type(str);
    if (type == UNKNOWN)
        return (not_displayable());
    if (type == CHAR)
        return (cast_from_char(str));
    else if (type == INT)
        return (cast_from_int(str));
    else if (type == FLOAT)
        return (cast_from_flt(str));
    else
        return (cast_from_d(str));
}