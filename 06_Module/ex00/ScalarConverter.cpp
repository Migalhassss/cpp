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
	(void)src;
	return *this;
}

void	ScalarConverter::convert(std::string const & input)
{
	int	_int = 0;
	float	_float = 0;
	double	_double = 0;
	char	_char;

	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf"
		|| input == "-inff" || input == "+inff" || input == "inff"
		|| input == "nanf")
	{
		_char = 0;
	}
	else
	{
		if (input.length() == 1 && !isdigit(input[0]))
		{
			_char = input[0];
			_int = static_cast<int>(_char);
			_float = static_cast<float>(_char);
			_double = static_cast<double>(_char);
		}
		else
		{
			_int = std::atoi(input.c_str());
			_double = std::atof(input.c_str());
			_float = static_cast<float>(_double);
			if (_double - _int == 0)
				_char = static_cast<char>(_int);
			else
				_char = 0;
		}
	}
	displayChar(input, _char);
	displayInt(input, _int);
	displayFloat(input, _float);
	displayDouble(input, _double);
}

void	ScalarConverter::displayChar(std::string const & input, char  _char)
{
	std::cout << "char: ";
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf"
		|| input == "-inff" || input == "+inff" || input == "inff"
		|| input == "nanf")
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isprint(_char))
		std::cout << "'" << _char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::displayInt(std::string const & input, int _int)
{
	long temp = std::atol(input.c_str());

	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf"
		|| input == "-inff" || input == "+inff" || input == "inff"
		|| input == "nanf")
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (temp > INT_MAX || temp < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
}

void	ScalarConverter::displayFloat(std::string const & input, float _float)
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf"
		|| input == "-inff" || input == "+inff" || input == "inff"
		|| input == "nanf")
	{
		std::cout << "float: " << input << "f" << std::endl;
		return ;
	}
	std::cout << "float: " << std::fixed  << std::setprecision(1) << _float << "f" << std::endl;
}

void	ScalarConverter::displayDouble(std::string const & input, double _double)
{
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf"
		|| input == "-inff" || input == "+inff" || input == "inff"
		|| input == "nanf")
	{
		std::cout << "double: " << input << std::endl;
		return ;
	}
	std::cout << "double: " << std::fixed  << std::setprecision(1) << _double << std::endl;
}
