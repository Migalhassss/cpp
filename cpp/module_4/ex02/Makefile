# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 19:49:00 by micarrel          #+#    #+#              #
#    Updated: 2024/02/10 19:49:00 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	AAnimal
C	=	c++

CFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	main.cpp	\
			Animal.cpp	\
			Dog.cpp	\
			Cat.cpp	\
			WrongAnimal.cpp	\
			WrongCat.cpp	\
			Brain.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME) $(OBJ)

$(NAME):	$(OBJ)
	$(C)	$(CFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all