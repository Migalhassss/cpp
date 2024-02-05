# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 16:45:30 by micarrel          #+#    #+#              #
#    Updated: 2024/01/28 16:45:30 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombie

C	=	c++

CFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	main.cpp	\
			Zombie.cpp	\
			zombieHorde.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME):
	$(C)	$(CFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all	