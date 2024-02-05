# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 20:33:02 by micarrel          #+#    #+#              #
#    Updated: 2024/01/23 20:33:02 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	theJob

C	=	c++

CFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	Account.cpp\
			tests.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME):
	$(C)	$(CFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	$(NAME)

re:	fclean	all