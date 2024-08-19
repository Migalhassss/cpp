/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:59:25 by micarrel          #+#    #+#             */
/*   Updated: 2024/08/19 22:23:25 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>
# include <sstream>
# include <string>
# include <algorithm>
# include <iomanip>
class BitcoinExchange
{
	private:
		std::string _filename;
		std::map<std::string, double> _exchangeRate;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const & filename);
		~BitcoinExchange();
		BitcoinExchange & operator=(BitcoinExchange const & src);
		bool	validFile();
		bool	validData(std::string const & line);
		bool	checkDate(std::string const & date);
		bool	checkValue(double value);
		bool	isLeapYear(int year);
		int		daysInMonth(int month, int year);
		void	showResult(std::string const & date, float value);
		void	loadData();
		void	execute();
		class invalid_file : public std::exception
		{
			virtual const char * what() const throw();
		};
};

#endif