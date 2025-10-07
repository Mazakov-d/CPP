/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:27:13 by dmazari           #+#    #+#             */
/*   Updated: 2025/10/07 19:16:40 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) {
    _data = cpy._data;
}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
    {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// BitcoinExchange::~BitcoinExchange() {}

// bool    isDatePossible(const std::string& date) {
//     size_t  i = 0;
    
//     while (i < date.size()) {
        
//     }
// }

std::string    BitcoinExchange::parseDataFile(const std::string& fileName) {
    std::ifstream	file(fileName.c_str(), std::ios_base::in);
    std::string     line;
    std::string     content;
    
    if (!file.is_open())
        throw (CanNotOpenFile(fileName));
    while (getline(file, line)) {
        content += line;
        content += '\n';
    }
    return content;
}



BitcoinExchange::CanNotOpenFile::CanNotOpenFile(const std::string& message) { 
    _message = "Can't open the file " + message + ".";
}

BitcoinExchange::CanNotOpenFile::~CanNotOpenFile() throw() {}

const char* BitcoinExchange::CanNotOpenFile::what() const throw() {
    return _message.c_str();
}