/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:51:48 by dmazari           #+#    #+#             */
/*   Updated: 2025/11/11 16:51:29 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

#define BAD_DATE 1
#define NOT_A_FLOAT 2

class BitcoinExchange {
private:
	std::map<std::string, float> _mapDateExchangeRate;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &cpy);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void parseDataFile();
	void executingConversion(const std::string& filename);
	float getExchangeRateByDate(const std::string& date);

		class BadInputFormat : public std::exception {
		public:
			BadInputFormat();
			virtual ~BadInputFormat() throw();

			virtual const char *what() const throw();
	};

	class BadCSVFormat : public std::exception {
		public:
			BadCSVFormat();
			virtual ~BadCSVFormat() throw();

			virtual const char *what() const throw();
	};

	class CanNotOpenFile : public std::exception {
	private:
		std::string _message;

	public:
		CanNotOpenFile(const std::string &);
		~CanNotOpenFile() throw();

		const char *what() const throw();
	};

	class NoExchangeRateForThisDate : public std::exception {
		private:
			std::string _message;
		public:
			NoExchangeRateForThisDate(const std::string &);
			virtual ~NoExchangeRateForThisDate() throw();

			const char *what() const throw();
	};
};

#endif