/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:41:40 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/11 03:41:40 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
	if (this != &src)
	{
		this->_input = src._input;
		this->_char = src._char;
		this->_int = src._int;
		this->_float = src._float;
		this->_double = src._double;
	}
	return *this;
}

void	ScalarConverter::convert(std::string const & input)
{

	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
	{
		this->_char = 0;
	}
	else
	{
		if (input.length() == 1 && !isdigit(input[0]))
		{
			this->_char = input[0];
			this->_int = static_cast<int>(this->_char);
			this->_float = static_cast<float>(this->_char);
			this->_double = static_cast<double>(this->_char);
		}
		else
		{
			this->_int = std::atoi(input.c_str());
			this->_double = std::atof(input.c_str());
			this->_float = static_cast<float>(this->_double);
			if (this->_double - this->_int == 0)
				this->_char = static_cast<char>(this->_int);
			else
				this->_char = 0;
		}
	}
	displayChar(input);
	displayInt(input);
	displayFloat(input);
	displayDouble(input);
}

void	ScalarConverter::displayChar(std::string const & input)
{
	std::cout << "char: ";
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isprint(this->_char))
		std::cout << "'" << this->_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::displayInt(std::string const & input)
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (this->_int > INT_MAX || this->_int < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->_int << std::endl;
}

void	ScalarConverter::displayFloat(std::string const & input)
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
	{
		std::cout << "float: " << input << "f" << std::endl;
		return ;
	}
	std::cout << "float: " << std::fixed  << std::setprecision(1) << this->_float << "f" << std::endl;
}

void	ScalarConverter::displayDouble(std::string const & input)
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
	{
		std::cout << "double: " << input << std::endl;
		return ;
	}
	std::cout << "double: " << std::fixed  << std::setprecision(1) << this->_double << std::endl;
}
