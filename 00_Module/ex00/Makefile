# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:59:06 by micarrel          #+#    #+#              #
#    Updated: 2024/01/22 17:59:06 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone

CXX	=	c++

CXXFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	megaphone.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX)	$(CXXFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all