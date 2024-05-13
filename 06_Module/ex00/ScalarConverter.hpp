/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:41:45 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/13 17:03:18 by micarrel         ###   ########.fr       */
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
		std::string	_input;
		char		_char;
		int			_int;
		float		_float;
		double		_double;
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();

		ScalarConverter & operator=(ScalarConverter const & rhs);

		void	convert(std::string const & input);
		void	displayChar(std::string const & input);
		void	displayInt(std::string const & input);
		void	displayFloat(std::string const & input);
		void	displayDouble(std::string const & input);

};

#endif