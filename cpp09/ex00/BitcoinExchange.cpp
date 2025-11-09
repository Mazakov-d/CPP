/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:27:13 by dmazari           #+#    #+#             */
/*   Updated: 2025/11/07 09:03:35 by dorianmazar      ###   ########.fr       */
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

int	stringToDate(int& year, int& month, int& day, const std::string& str) {
	std::istringstream	iss(str);
	char				firstSeparator;
	char				secondSeparator;

	iss >> year >> firstSeparator >> month >> secondSeparator >> day;
	if (iss.fail())
		throw (BitcoinExchange::ConvertionFailed());
	if (!iss.fail() || firstSeparator != '-' || secondSeparator != '-')
		return (BAD_DATE);
	return (EXIT_SUCCESS);
}

bool	isALeapYear(int year) {
	if (year % 4)
		return false;
	if (year % 400)
		return false;
	return true;
}

bool	isYearAvailable(int year, int month, int day)
{
	int		shortMonth[4] = {4, 6, 9, 10};
	int		longMonth[7] = {1, 3, 5, 7, 8, 10, 12};
	int		sizeShortMonth = 4;
	int		sizeLongMonth = 7;
	bool	leapYear = isALeapYear(year);

	if ((year < 2009 && month == 1) || year > 2025)
		return false;
	if (month < 1 || month > 12)
		return false;
}

bool    isDatePossible(const std::string& date) {
    size_t  i = 0;
    
    while (i < date.size()) {
        
    }
}

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

BitcoinExchange::ConvertionFailed::ConvertionFailed() {}

BitcoinExchange::ConvertionFailed::~ConvertionFailed() {}

const char* BitcoinExchange::ConvertionFailed::what() const throw() {
	return "A convertion failed";
}

BitcoinExchange::CanNotOpenFile::CanNotOpenFile(const std::string& message) { 
    _message = "Can't open the file " + message + ".";
}

BitcoinExchange::CanNotOpenFile::~CanNotOpenFile() throw() {}

const char* BitcoinExchange::CanNotOpenFile::what() const throw() {
    return _message.c_str();
}