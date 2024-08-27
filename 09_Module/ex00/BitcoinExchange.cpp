/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:59:23 by micarrel          #+#    #+#             */
/*   Updated: 2024/08/27 12:24:14 by micarrel         ###   ########.fr       */
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
	execute();
}

bool	BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int	BitcoinExchange::daysInMonth(int month, int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || 
		month == 8 || month == 10 || month == 12) {
		return 31;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	} else if (month == 2) {
		return isLeapYear(year) ? 29 : 28;
	} else {
		std::cout << "Invalid month" << std::endl;
		return 0;
	}
}

bool BitcoinExchange::checkDate(std::string const & date)
{
	
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad date format => " << date << std::endl;
		return false;
	}


	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	
	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	
	if (year < 2000 || year > 2020 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::checkValue(double valueSTR)
{
	std::ostringstream ss; 
	ss << valueSTR; 
	std::string value = ss.str();
	double numValue = std::atof(value.c_str());

	
	if (numValue < 0.0 || numValue > 1000.0)
	{
		if (numValue < 0.0)
			std::cout << "Error: not a positive number." << std::endl;
		if (numValue > 1000.0)
			std::cout << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::showResult(std::string const & date, double value)
{
	std::map<std::string, double>::iterator it = this->_exchangeRate.lower_bound(date);
	
	if (it == this->_exchangeRate.end() || it->first != date)
		if (it != _exchangeRate.begin())
			--it;

	if (it != this->_exchangeRate.end())
	{
		double rate = it->second;
		double convertedValue = value * rate;

		
		std::ostringstream formattedOutput;
		formattedOutput << date << " => " << value << " = " << convertedValue;

		
		std::cout << formattedOutput.str() << std::endl;
	}
}


BitcoinExchange::~BitcoinExchange()
{
}


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
	std::ifstream file(_filename.c_str());
	if (file.is_open())
		return false;
	return true;
}


void	BitcoinExchange::loadData()
{
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	double value;

	while (std::getline(file, line))
	{
		std::size_t commaPos = line.find(','); 
		if (commaPos != std::string::npos)
		{
			date = line.substr(0, commaPos); 
			std::string valueStr = line.substr(commaPos + 1); 
			value = std::atof(valueStr.c_str()); 
			_exchangeRate[date] = value;
		}
	}
}

void BitcoinExchange::execute()
{
	std::ifstream file(_filename.c_str());
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty() || line == "date | value")
			;
		else
		{		
			std::istringstream temp(line);
			std::string date, valueStr;
			std::getline(temp, date, '|');
			std::getline(temp, valueStr);

			if (!date.empty() && date.find_last_not_of(" \n\r\t") != std::string::npos)
				date = date.substr(0, date.find_last_not_of(" \n\r\t")+1);
			if (!valueStr.empty() && valueStr.find_first_not_of(" \n\r\t") != std::string::npos)
				valueStr = valueStr.substr(valueStr.find_first_not_of(" \n\r\t"));
			
			if (checkDate(date) && checkValue(atof(valueStr.c_str())))
				showResult(date, atof(valueStr.c_str()));
		}
	}
}

const char* BitcoinExchange::invalid_file::what() const throw()
{
	return "Error: Invalid file";
}

