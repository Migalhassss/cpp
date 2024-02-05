/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:56:48 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/01 14:56:48 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::ifstream filename(av[1]);
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return (1);
	}
	if (filename.fail())
	{
		std::cout << "Error: file not found" << std::endl;
		return (1);
	}
	std::stringstream buffer;
	buffer << filename.rdbuf();
	std::string file = buffer.str();
	if (file.empty())
	{
		std::cout << "Error: empty file" << std::endl;
		return (1);
	}
	ft_replace(file, s1, s2);
	std::ofstream output(((std::string(av[1])) + std::string(".replace")).c_str());
	if (output.fail())
	{
		std::cout << "Error: file not found" << std::endl;
		return (1);
	}
	output << file;
	output.close();
	return (0);
}