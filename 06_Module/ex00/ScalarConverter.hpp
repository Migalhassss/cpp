/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:41:45 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/11 03:41:45 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

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
		void	displayChar();
		void	displayInt();
		void	displayFloat();
		void	displayDouble();

};

#endif