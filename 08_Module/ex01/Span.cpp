/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:47:49 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/20 16:47:49 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

Span::Span() : _N(0), _index(0), _array(NULL) {}

Span::Span(unsigned int N) : _N(N), _index(0), _array(new int[N]) {}

Span::Span(const Span &src) : _N(src._N), _index(src._index), _array(new int[src._N])
{
	*this = src;
}

Span::~Span()
{
	delete [] _array;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src) {
		delete [] _array;
		_array = new int[src._N];
		_N = src._N;
		_index = src._index;
		for (unsigned int i = 0; i < _index; i++)
			_array[i] = src._array[i];
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_index >= _N)
		throw std::exception();
	_array[_index] = n;
	_index++;
}

int Span::shortestSpan()
{
	if (_index <= 1)
		throw std::exception();
	int min = INT_MAX;
	for (unsigned int i = 0; i < _index; i++)
	{
		for (unsigned int j = i + 1; j < _index; j++)
		{
			if (abs(_array[i] - _array[j]) < min)
				min = abs(_array[i] - _array[j]);
		}
	}
	return min;
}

int Span::longestSpan()
{
	if (_index <= 1)
		throw std::exception();
	int max = INT_MIN;
	for (unsigned int i = 0; i < _index; i++)
	{
		for (unsigned int j = i + 1; j < _index; j++)
		{
			if (abs(_array[i] - _array[j]) > max)
				max = abs(_array[i] - _array[j]);
		}
	}
	return max;
}

void Span::printnumbers()
{
	for (unsigned int i = 0; i < _index; i++)
		std::cout << _array[i] << " | ";
	std::cout << std::endl;
}



