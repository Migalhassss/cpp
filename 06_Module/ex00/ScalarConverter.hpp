/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:41:45 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/22 14:20:00 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <climits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
	public:
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & rhs);
		static void	convert(std::string const & input);
		static void	displayChar(std::string const & input, char _char);
		static void	displayInt(std::string const & input, int _int);
		static void	displayFloat(std::string const & input, float _float);
		static void	displayDouble(std::string const & input, double _double);
};

#endif