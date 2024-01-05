/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:16:30 by eorer             #+#    #+#             */
/*   Updated: 2024/01/05 16:39:12 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

	//CANON
BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string dataPath)
{
	std::cout << "Data constructor called" << std::endl;
	this->_initialiseExchange(dataPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
	std::cout << "Cpy constructor called" << std::endl;
	*this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cpy)
{
	if (this == &cpy)
		return (*this);
	this->_exchange = cpy._exchange;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor called" << std::endl;
}

std::map<std::string, double>	BitcoinExchange::_getMap()
{
	return (this->_exchange);
}

void	BitcoinExchange::_initialiseExchange(const std::string dataPath)
{
	std::ifstream	dataFile;
	std::string	line;

	dataFile.open(dataPath.c_str());
	if (!dataFile.is_open())
		throw BitcoinExchange::DataFileException();
	getline(dataFile, line);
	while (getline(dataFile, line))
	{
		this->_exchange[line.substr(0, line.find(","))] = strtod(line.substr(line.find(",") + 1, line.length()).c_str(), NULL);
	}
	dataFile.close();
}

void	BitcoinExchange::analyse(std::string input)
{
	std::ifstream	file;
	std::string	line;
	std::pair<std::string, double>	item;
	std::map<std::string, double>::iterator it;

	file.open(input.c_str());
	if (!file.is_open())
		throw BitcoinExchange::InputFileException();
	getline(file, line);
	if (line != "date | value")
		throw BitcoinExchange::FormatErrorException();
	while (getline(file, line))
	{
		try
		{
			item = _analyseFormat(line);
			it = this->_exchange.upper_bound(item.first);
			it--;
			if (it == this->_exchange.end())
				std::cout << "Date not found" << std::endl;
			else
				std::cout << item.first << " => " << item.second << " = " << it->second * item.second << std::endl;
		}
		catch (std::string error)
		{
			std::cerr << "Error: " << error << std::endl;
		}
		catch (std::exception &error)
		{
			std::cerr << "Error: " << error.what() << std::endl;
		}
	}
	file.close();
}

std::pair<std::string, double>	BitcoinExchange::_analyseFormat(std::string line)
{
	std::pair<std::string, double>	item;
	std::string	str;
	int	num;

	if (line.empty())
		throw ("File is empty");
	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	if (line.find("|") >= line.length())
		throw ("bad input => " + line);
	item.first = line.substr(0, line.find("|"));
	item.second = strtod(line.substr(line.find("|") + 1, line.length()).c_str(), NULL);

		//Date analysis
	str = item.first.substr(0, item.first.find("-"));
	num = atoi(str.c_str());
	if (num > 2025 || num < 2000)
		throw ("bad input => " + item.first);
	str = item.first.substr(item.first.find("-") + 1, item.first.rfind("-") - item.first.find("-"));
	num = atoi(str.c_str());
	if (num > 12 || num <= 0)
		throw ("bad input => " + item.first);
	str = item.first.substr(item.first.rfind("-") + 1, item.first.length());
	num = atoi(str.c_str());
	if (num > 31 || num <= 0)
		throw ("bad input => " + item.first);

		//Amount analysis
	if (item.second > 1000)
		throw (static_cast<std::string>("too large number"));
	if (item.second < 0)
		throw (static_cast<std::string>("negative number"));

	return (item);
}

const char*	BitcoinExchange::DataFileException::what() const throw()
{
	return ("No data file was found");
}

const char*	BitcoinExchange::InputFileException::what() const throw()
{
	return ("No input file was found");
}

const char*	BitcoinExchange::FormatErrorException::what() const throw()
{
	return ("Format error");
}
