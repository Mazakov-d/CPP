/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:51:48 by dmazari           #+#    #+#             */
/*   Updated: 2025/11/07 08:50:20 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <map>
# include <exception>
# include <fstream>
# include <sstream>
# include <unistd.h>

# define BAD_DATE 1

class BitcoinExchange {
	private:
		std::map<std::string, int>  _data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		std::string parseDataFile(const std::string&);


		class ConvertionFailed: std::exception {
			public:
				ConvertionFailed();
				~ConvertionFailed();

				const char* what() const throw();
		};

		class CanNotOpenFile: std::exception {
			private:
				std::string	_message;
			public:
				CanNotOpenFile(const std::string&);
				~CanNotOpenFile() throw();

				const char* what() const throw();
		};
};

#endif