/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:01:52 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/20 18:01:52 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		virtual ~MutantStack() {}

		MutantStack &operator=(const MutantStack &copy)
		{
			if (this == &copy)
				return (*this);
			std::stack<T>::operator=(copy);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin()
		{
			return (std::stack<T>::c.begin());
		}

		iterator end()
		{
			return (std::stack<T>::c.end());
		}
};

#endif