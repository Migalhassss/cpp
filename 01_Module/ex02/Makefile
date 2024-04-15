# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 18:13:38 by micarrel          #+#    #+#              #
#    Updated: 2024/01/28 18:13:38 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	brain

C	=	c++

CFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	main.cpp	\

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(C)	$(CFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all