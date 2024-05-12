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
		this->_int = 0;
		this->_float = std::stof(input);
		this->_double = std::stod(input);
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
			this->_int = std::stoi(input);
			this->_char = static_cast<char>(this->_int);
			this->_float = static_cast<float>(this->_int);
			this->_double = static_cast<double>(this->_int);
		}
	}
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();
}

void	ScalarConverter::displayChar()
{
	std::cout << "char: ";
	if (isprint(this->_char))
		std::cout << "'" << this->_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::displayInt()
{
	if (this->_char_)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->_int << std::endl;
}

void	ScalarConverter::displayFloat()
{
	std::cout << "float: " << this->_float << "f" << std::endl;
}

void	ScalarConverter::displayDouble()
{
	std::cout << "double: " << this->_double << std::endl;
}




/*
fix nan and inf values
fix include
some more tests

*/


