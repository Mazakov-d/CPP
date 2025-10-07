/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:51:48 by dmazari           #+#    #+#             */
/*   Updated: 2025/10/07 19:10:16 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <map>
# include <exception>
# include <fstream>


class BitcoinExchange {
	private:
		std::map<std::string, int>  _data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& cpy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		std::string parseDataFile(const std::string&);      

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