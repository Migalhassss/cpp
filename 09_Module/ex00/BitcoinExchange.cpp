/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:59:23 by micarrel          #+#    #+#             */
/*   Updated: 2024/08/19 22:23:08 by micarrel         ###   ########.fr       */
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
	// Check if the date has the correct format
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad date format => " << date << std::endl;
		return false;
	}

	// Extract the year, month and day from the date string
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	// Convert the year, month and day strings to integers
	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	// Check if the year, month and day are valid
	if (year < 2000 || year > 2020 || month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year))
	{
		std::cout << "Error: bad date => " << date << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::checkValue(double valueSTR)
{
	std::ostringstream ss; // Create a stringstream object
	ss << valueSTR; // Feed the double value into it
	std::string value = ss.str();
	// Check if the string contains only digits and at most one decimal point
	if (value.find_first_not_of("0123456789.") != std::string::npos || std::count(value.begin(), value.end(), '.') > 1)
	{
		std::cout << "Error: bad value => " << value << std::endl;
		return false;
	}
	// Convert the string to a double
	char* end;
	double numValue = std::strtod(value.c_str(), &end);

	// Check if the entire string was converted and if the number is within the range
	if (*end != '\0' || numValue < 0.0 || numValue > 1000.0)
	{
		std::cout << "Error: value out of range or invalid => " << value << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::showResult(std::string const & date, float value)
{
	std::map<std::string, double>::iterator it = this->_exchangeRate.find(date);
    if (it != this->_exchangeRate.end())
    {
        double rate = it->second;
        double convertedValue = value * rate;

        // Use ostringstream for formatting
        std::ostringstream formattedOutput;
        formattedOutput << date << " => " << value << " = " << convertedValue;

        // Print the formatted string
        std::cout << formattedOutput.str() << std::endl;
    }
    else
    {
        std::cout << "Error: Exchange rate for " << date << " not found." << std::endl;
    }
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
	std::ifstream file(_filename.c_str());
	if (file.is_open())
		return false;
	return true;
}


void	BitcoinExchange::loadData()
{
	std::ifstream file(_filename.c_str());
	std::string line;
	std::string date;
	float value;


	while (std::getline(file, line))
	{
		std::size_t commaPos = line.find(','); // Find the comma position
		std::size_t pipePos = line.find('|'); // Find the pipe position

		if (pipePos != std::string::npos)
		{
			date = line.substr(0, pipePos - 1); // Extract the date
			std::string valueStr = line.substr(pipePos + 1); // Extract the value string
			value = std::atof(valueStr.c_str()); // Convert the value string to float
			_exchangeRate[date] = value;
		}
		else if (commaPos != std::string::npos)
		{
			date = line.substr(0, commaPos); // Extract the date
			std::string valueStr = line.substr(commaPos + 1); // Extract the value string
			value = std::atof(valueStr.c_str()); // Convert the value string to float
			_exchangeRate[date] = value;
		}
		else
		{
			_exchangeRate[date] = 0;
		}
		
		// std::cout << "debug: " << date << "| |" << value << std::endl;
	}	
	// while (std::getline(file, line))
	// {
	// 	std::size_t commaPos = line.find(','); // Find the comma position
	// 	if (commaPos != std::string::npos)
	// 	{
	// 		date = line.substr(0, commaPos); // Extract the date
	// 		std::string valueStr = line.substr(commaPos + 1); // Extract the value string
	// 		value = std::atof(valueStr.c_str()); // Convert the value string to float
	// 		_exchangeRate[date] = value;
	// 	}
	// 	std::cout << "debug: " << date << " " << value << std::endl;
	// }
}

void BitcoinExchange::execute()
{
	std::map<std::string, double>::iterator it = _exchangeRate.begin();
	std::ifstream file(_filename.c_str());
		std::string line;
		while (std::getline(file, line))
		{
			if (!line.empty())
			{
				if (checkDate(it->first) && checkValue(it->second))
					showResult(it->first, it->second);
				// else
				// 	std::cout << "Error: bad input => " << line << std::endl;
				it++;
			}
		}
}

const char* BitcoinExchange::invalid_file::what() const throw()
{
	return "Error: Invalid file";
}

