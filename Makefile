#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/23 10:13:06 by kzakharc          #+#    #+#              #
#    Updated: 2017/08/15 12:02:11 by kzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = asm
CC = gcc
FLAG = -Wall -Wextra -Werror
LIBFT = ./Lib/big_libft.a
OBJ = $(patsubst %.c,%.o,$(wildcard ./src/*.c))

.PHONY: libft

all : $(NAME)

$(NAME) : $(OBJ) libft
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT)

libft:
	make -C ./Lib

%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make clean -C ./Lib

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./Lib

re: fclean all