/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:07:25 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/24 21:06:26 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <cstdlib>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN & operator=(RPN const & src);




};	

	void	rpn(const std::string& inputStr);
	void	displayStack(std::stack<int> stack);
	bool checkInput(const std::string& inputStr);

#endif	