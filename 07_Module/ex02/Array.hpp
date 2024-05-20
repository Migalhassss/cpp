/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:45:12 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/20 14:46:54 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstdlib>

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T		*_array;
		unsigned int	_size;
	public:
		Array(void) : _array(NULL), _size(0) {};
		Array(unsigned int n) : _array(new T[n]), _size(n) {};
		Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
			*this = src;
		}
		~Array(void) {
			delete [] _array;
		}
		class	OutOfBound : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Out of bound";
				}
		};
		Array &operator=(const Array &src) {
			if (this != &src) {
				delete [] _array;
				_array = new T[src._size];
				_size = src._size;
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			return *this;
		}
		T &operator[](unsigned int n) {
			if (n >= _size)
				throw OutOfBound();
			return _array[n];
		}

		unsigned int size() const 
		{
			return _size;
		}
};

#endif