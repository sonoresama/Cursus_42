/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:06:13 by eorer             #+#    #+#             */
/*   Updated: 2024/01/05 16:22:30 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <stdlib.h>
# include <stdio.h>
# include <algorithm>

class	BitcoinExchange{
	public :
		BitcoinExchange();
		BitcoinExchange(const std::string dataPath);
		BitcoinExchange(const BitcoinExchange& cpy);
		BitcoinExchange& operator=(const BitcoinExchange& cpy);
		~BitcoinExchange();
		
		std::map<std::string, double> _getMap();
		void	analyse(std::string input);

		class DataFileException : public std::exception
		{
			const char* what() const throw();
		};

		class InputFileException : public std::exception
		{
			const char* what() const throw();
		};

		class FormatErrorException : public std::exception
		{
			const char* what() const throw();
		};

	private:
		std::map<std::string, double>	_exchange;
		void	_initialiseExchange(const std::string dataPath);
		std::pair<std::string, double>	_analyseFormat(std::string line);
};

#endif
