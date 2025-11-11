/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:27:13 by dmazari           #+#    #+#             */
/*   Updated: 2025/11/11 17:03:51 by mazakov          ###   ########.fr       */
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

bool	isSeparator(char c, const std::string& separators) {
	for (size_t i = 0; i < separators.size(); ++i) {
		if (separators[i] == c)
			return true;
	}
	return false;
}

std::vector<std::string>	ftSplit(const std::string& str, const std::string& separators) {
	std::vector<std::string>	tokens;

	for (size_t i = 0; i < str.size(); ++i) {
		if (isSeparator(str[i], separators))
			++i;
		else
		{
			size_t	j = i;
			while (j < str.size() && !isSeparator(str[j], separators))
				j++;
			tokens.push_back(str.substr(i, j - i));
			i = j;
		}
	}
	return tokens;
}

void BitcoinExchange::parseDataFile() {
	std::map<std::string, float>	mapDateExchangeRate;
	std::vector<std::string>		content;
	std::ifstream					file("data.csv", std::ios_base::in);
	std::string						line;

	if (!file.is_open())
		throw(CanNotOpenFile("data.csv"));
	while (getline(file, line)) {
		content.push_back(line);
	}

	int		year;
	char	firstSeparator;
	int		month;
	char	secondSeparator;
	int		day;
	float	exchangeRate;

	if (content[0] != "date,exchange_rate")
		throw(BadCSVFormat());

	for (size_t i = 1; i < content.size(); ++i) {

		std::vector<std::string> tokens = ftSplit(content[i], ",");
		if (tokens.size() == 2){
			std::istringstream	issDate(tokens[0]);
			std::istringstream	issExchangeRate(tokens[1]);

			issDate >> year >> firstSeparator >> month >> secondSeparator >> day ;
			issExchangeRate >> exchangeRate;
			if (issDate.fail() || issExchangeRate.fail())
				continue;
			if (!issExchangeRate.eof() || !issDate.eof() || firstSeparator != '-' || secondSeparator != '-' || !isAVailableDate(year, month, day))
				continue;
			if (exchangeRate < 0)
			{
				std::cerr << "Error: Can't have a negative exchange rate." << std::endl;
				continue;
			}
			mapDateExchangeRate[tokens[0]] = exchangeRate;
		}
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

void	BitcoinExchange::executingConversion(const std::string& fileName) {
	std::vector<std::string>		content;
	std::ifstream					file(fileName.c_str(), std::ios_base::in);
	std::string						line;

	if (!file.is_open())
		throw(CanNotOpenFile(fileName));
	while (getline(file, line)) {
		content.push_back(line);
	}

	int		year;
	char	firstSeparator;
	int		month;
	char	secondSeparator;
	int		day;
	float	value;

	if (content[0] != "date | value")
		throw(BadInputFormat());

	for (size_t i = 1; i < content.size(); ++i) {

		std::vector<std::string> tokens = ftSplit(content[i], " | ");
		if (tokens.size() == 2) {
			std::istringstream	issDate(tokens[0]);
			std::istringstream	issValue(tokens[1]);

			issDate >> year >> firstSeparator >> month >> secondSeparator >> day ;
			issValue >> value;
			if (issDate.fail() || issValue.fail())
				std::cerr << "Error: The format of this line: '" << content[i] << "' is not an appropriate one." << std::endl;
			else if (!issValue.eof())
				std::cerr << "Error: A float was expected for the value and got: " << tokens[1] << std::endl;
			else if (!issDate.eof() || firstSeparator != '-' || secondSeparator != '-')
				std::cerr << "Error: The format of date is not valid, format excepted: YYYY-MM-DD and get: " << tokens[0] << std::endl;
			else if (!isAVailableDate(year, month, day))
				continue;
			else if (value < 0)
				std::cerr << "Error: Can't have a negative value and get: " << value << std::endl;
			else if (value > 1000)
				std::cerr << "Error: The value can't be greater than 1000." << std::endl;
			else {
				try {
					std::cout << tokens[0] << " => " << value << " = " << value * (getExchangeRateByDate(tokens[0])) << std::endl;
				}
				catch (NoExchangeRateForThisDate& e) {
					std::cerr << e.what() << std::endl;
				}
			}
				
		}
		else {
			std::cerr << "Error: The format of this line: '" << content[i] << "' is not an appropriate one." << std::endl;
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