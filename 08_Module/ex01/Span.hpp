/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:12:34 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/20 16:12:34 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <climits>
# include <cmath>

class Span
{
	private:
		unsigned int		_N;
		unsigned int		_index;
		int					*_array;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void	printnumbers();
};

#endif