# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 15:40:32 by rvalenti          #+#    #+#              #
#    Updated: 2019/01/16 14:11:26 by mabouce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		miniprintf.c			\

LIBFT		=		libft/
OBJ			=		$(SRCS:.c=.o)
CC			=		gcc -Wall -Wextra -Werror
NAME		=		libftminiprintf.a
.PHONY		=		all $(NAME) $(OBJ) clean fclean re

_UNDER=$'\x1b[4m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'

all:	$(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	@echo "$(_WHITE)$(NAME)\t$(_GREEN)[OK]$(_END)"

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all

%.o: %.c
	$(CC) -I $(LIBFT) -I includes/ -c $< -o $@
