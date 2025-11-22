/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:27:13 by dmazari           #+#    #+#             */
/*   Updated: 2025/11/22 16:26:15 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	_mapDateExchangeRate = cpy._mapDateExchangeRate;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_mapDateExchangeRate = other._mapDateExchangeRate;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool isALeapYear(int year) {
	if (!(year % 4))
		return true;
	if (!(year % 400))
		return true;
	return false;
}

bool isAVailableDate(int year, int month, int day) {
	bool leapYear = isALeapYear(year);

	if (month < 1 || month > 12)
	{
		std::cerr << "Error: The month of '" << year << "-" << month << "-" << day << "' is not valid." << std::endl;
		return false;
	}
	if (day < 1 || day > 31)
	{
		std::cerr << "Error: The day of '" << year << "-" << month << "-" << day << "' is not valid." << std::endl;
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		std::cerr << "Error: The day of '" << year << "-" << month << "-" << day << "' is not valid." << std::endl;
		return false;
	}
	if (month == 2 && day > 29)
	{
		std::cerr << "Error: The date '" << year << "-" << month << "-" << day << "' is not valid." << std::endl;
		return false;
	}
	if (month == 2 && day > 28 && !leapYear)
	{
		std::cerr << "Error: The date '" << year << "-" << month << "-" << day << "' is not valid because is not a leap year." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::parseDataFile() {
	std::map<std::string, float>	mapDateExchangeRate;
	std::ifstream					file("data.csv", std::ios_base::in);
	std::string						line;

	if (!file.is_open())
		throw(CanNotOpenFile("data.csv"));
	if (!getline(file, line))
		throw (BadCSVFormat());

	int		year, month, day;
	char	firstSeparator, secondSeparator;
	float	exchangeRate;

	if (line != "date,exchange_rate")
		throw(BadCSVFormat());

	while (std::getline(file, line)) {
		size_t	pos = line.find(',');
		if (pos == std::string::npos)
			continue ;

		std::string	date = line.substr(0, pos);
		std::string	rate = line.substr(pos + 1);
		std::istringstream	issDate(date);
		std::istringstream	issExchangeRate(rate);

		issDate >> year >> firstSeparator >> month >> secondSeparator >> day ;
		issExchangeRate >> exchangeRate;
		if (issDate.fail() || issExchangeRate.fail())
			continue;
		if (!issDate.eof() || !issExchangeRate.eof())
			continue;
		if (firstSeparator != '-' || secondSeparator != '-' || !isAVailableDate(year, month, day))
			continue;
		if (exchangeRate < 0)
		{
			std::cerr << "Error: Can't have a negative exchange rate." << std::endl;
			continue;
		}
		mapDateExchangeRate[date] = exchangeRate;
	}
	if (mapDateExchangeRate.empty())
		throw (BadCSVFormat());
	_mapDateExchangeRate = mapDateExchangeRate;
}

float BitcoinExchange::getExchangeRateByDate(const std::string& date) {
	std::map<std::string, float>::iterator it = _mapDateExchangeRate.lower_bound(date);
	if (it == _mapDateExchangeRate.begin() && it->first != date)
		throw (NoExchangeRateForThisDate(date));
	else if (it == _mapDateExchangeRate.end() || it->first > date)
		--it;
	return it->second;
}

void BitcoinExchange::executingConversion(const std::string& fileName) {
    std::ifstream file(fileName.c_str());
    std::string line;

    if (!file.is_open())
        throw CanNotOpenFile(fileName);

    if (!std::getline(file, line) || line != "date | value")
        throw BadInputFormat();

    int year, month, day;
    char sep1, sep2;
    float value;

    while (std::getline(file, line)) {

        size_t pos = line.find(" | ");
        if (pos == std::string::npos) {
            std::cerr << "Error: The format of this line: '" << line
                      << "' is not an appropriate one." << std::endl;
            continue;
        }

        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 3);

        std::istringstream issDate(date);
        issDate >> year >> sep1 >> month >> sep2 >> day;
        std::istringstream issValue(valueStr);
        issValue >> value;

        if (issDate.fail() || issValue.fail()) {
            std::cerr << "Error: The format of this line: '" << line
                      << "' is not an appropriate one." << std::endl;
            continue;
        }
        if (!issValue.eof()) {
            std::cerr << "Error: A float was expected for the value and got: "
                      << valueStr << std::endl;
            continue;
        }
        if (!issDate.eof() || sep1 != '-' || sep2 != '-') {
            std::cerr << "Error: The format of date is not valid, expected YYYY-MM-DD and got: "
                      << date << std::endl;
            continue;
        }
        if (!isAVailableDate(year, month, day))
            continue;
        if (value < 0) {
            std::cerr << "Error: Can't have a negative value and got: "
                      << value << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: The value can't be greater than 1000." << std::endl;
            continue;
        }
        try {
            float rate = getExchangeRateByDate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
        catch (NoExchangeRateForThisDate& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

//exception classes

BitcoinExchange::BadInputFormat::BadInputFormat() {}

BitcoinExchange::BadInputFormat::~BadInputFormat() throw() {}

const char *BitcoinExchange::BadInputFormat::what() const throw() {
	return "Bad input format, strictly expected: 'date | value'";
}

BitcoinExchange::BadCSVFormat::BadCSVFormat() {}

BitcoinExchange::BadCSVFormat::~BadCSVFormat() throw() {}

const char *BitcoinExchange::BadCSVFormat::what() const throw() {
	return "The expected format for the data.cvs is 'date,exchange_rate'";
}

BitcoinExchange::CanNotOpenFile::CanNotOpenFile(const std::string &message) {
	_message = "Can't open the file " + message + ".";
}

BitcoinExchange::CanNotOpenFile::~CanNotOpenFile() throw() {}

const char *BitcoinExchange::CanNotOpenFile::what() const throw() {
	return _message.c_str();
}

BitcoinExchange::NoExchangeRateForThisDate::NoExchangeRateForThisDate(const std::string& message) {
	if (message.empty())
		_message = "There is no exchange rate for the date: " + message;
	else
		_message = "There is no exchange rate";
}

BitcoinExchange::NoExchangeRateForThisDate::~NoExchangeRateForThisDate() throw() {}

const char *BitcoinExchange::NoExchangeRateForThisDate::what() const throw() {
	return _message.c_str();
}