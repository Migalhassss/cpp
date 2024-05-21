/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:59:25 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/21 13:38:06 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>

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
		void	loadData();
		class invalid_file : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Error: Invalid file";
			}
		};
}

#endif