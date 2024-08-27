/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:07:23 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/24 19:59:00 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN & RPN::operator=(RPN const & src)
{
	(void)src;
	return *this;
}

bool checkInput(const std::string& inputStr)
{
	if (inputStr.empty())
		return false;
	for (size_t i = 0; i < inputStr.size(); i++)
	{
		if (i % 2 == 0 && (!isdigit(inputStr[i]) && inputStr[i] != '+' && inputStr[i] != '-' && inputStr[i] != '*' && inputStr[i] != '/'))
			return false;
		if (i % 2 != 0 && inputStr[i] != ' ')
			return false;
		if (i > 0 && (inputStr[i] == '+' || inputStr[i] == '-' || inputStr[i] == '*' || inputStr[i] == '/') &&
			(inputStr[i - 1] == '+' || inputStr[i - 1] == '-' || inputStr[i - 1] == '*' || inputStr[i - 1] == '/'))
			return false;
	}
	return true;
}

void rpn(const std::string& inputStr)
{
	std::stack<int> stack;
	std::stringstream ss(inputStr);
	std::string input;
	int a;
	int b;

	while (ss >> input)
	{
		if (input == "+" || input == "-" || input == "*" || input == "/")
		{
			if (stack.size() < 2)
			{
				std::cout << "Not enough elements in the stack" << std::endl;
				continue;
			}
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			if (input == "+")
				stack.push(b + a);
			else if (input == "-")
				stack.push(b - a);
			else if (input == "*")
				stack.push(b * a);
			else if (input == "/")
				stack.push(b / a);
		}
		else
		{
			stack.push(std::atoi(input.c_str()));
		}
	}
	displayStack(stack);
}

void displayStack(std::stack<int> stack)
{
	std::stack<int> tmp = stack;

	if (stack.size() > 1)
	{
		std::cout << "Error: invalid input" << std::endl;
		return ;
	}
	std::cout << "Result: ";
	while (!tmp.empty())
	{
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	std::cout << std::endl;
}

