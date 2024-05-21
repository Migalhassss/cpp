# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 12:58:18 by micarrel          #+#    #+#              #
#    Updated: 2024/05/21 12:58:41 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	btc
CXX	=	c++

CXXFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98	

FILES	=	main.cpp		\
			BitcoinExchange.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME) $(OBJ)

$(NAME):	$(OBJ)
	$(CXX)	$(CXXFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all