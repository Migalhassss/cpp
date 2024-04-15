# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 18:56:40 by micarrel          #+#    #+#              #
#    Updated: 2024/02/11 18:56:40 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	materia
C	=	c++

CFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	main.cpp	\
			AMateria.cpp	\
			Character.cpp	\
			Cure.cpp	\
			Ice.cpp	\
			MateriaSource.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME) $(OBJ)

$(NAME):	$(OBJ)
	$(C)	$(CFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all