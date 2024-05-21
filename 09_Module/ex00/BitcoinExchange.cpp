/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:59:23 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/21 13:38:27 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string const & filename)
{
	_filename = filename;
	if (validFile())
		throw invalid_file();
	loadData();
	
}

BitcoinExchange::~BitcoinExchange()
{
}



//Check this
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	if (this != &src)
	{
		this->_filename = src._filename;
		this->_exchangeRate = src._exchangeRate;
	}
	return *this;
}

bool	BitcoinExchange::validFile()
{
	std::ifstream file(_filename);
	if (!file.is_open())
		return false;
	return true;
}

bool	BitcoinExchange::validData(std::string const & line)
{
	if (line.length() < 4)
		return false;
	if (line[3] != '=')
		return false;
	if (line.substr(4).find_first_not_of("0123456789.") != std::string::npos)
		return false;
	return true;
}

void	BitcoinExchange::loadData()
{
	std::ifstream file(_filename);
	std::string line;
	std::string currency;
	double rate;

	while (std::getline(file, line))
	{
		if (validData(line))
		currency = line.substr(0, 3);
		rate = std::stod(line.substr(4));
		_exchangeRate[currency] = rate;
	}
}

