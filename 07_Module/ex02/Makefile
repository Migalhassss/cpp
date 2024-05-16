# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 12:42:39 by micarrel          #+#    #+#              #
#    Updated: 2024/05/16 14:43:30 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Array
CXX	=	c++

CXXFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98	

FILES	=	main.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME) $(OBJ)

$(NAME):	$(OBJ)
	$(CXX)	$(CXXFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all