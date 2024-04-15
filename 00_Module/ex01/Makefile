# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 20:40:26 by micarrel          #+#    #+#              #
#    Updated: 2024/01/22 20:40:26 by micarrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

C	=	c++

CFLAGS	=	-Wall	-Wextra	-Werror	-g	-std=c++98

FILES	=	PhoneBook.cpp\
			Contact.cpp \
			main.cpp

OBJ	=	$(FILES:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(C)	$(CFLAGS)	$(FILES)	-o	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm	-f $(NAME)

re:	fclean	all