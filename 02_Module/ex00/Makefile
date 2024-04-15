# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 05:35:37 by micarrel          #+#    #+#              #
#    Updated: 2024/02/08 05:53:23 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Fixed

C	=	c++

CFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	main.cpp	\
			Fixed.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(C)	$(CFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all