# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minimarmeto <minimarmeto@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 11:01:46 by dgomez-b          #+#    #+#              #
#    Updated: 2024/01/28 23:05:56 by minimarmeto      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
BIN			=	./.bin/
SRC			=	./src/
INC			=	./includes/
SRCS		=	main.c
OBJS		=	$(addprefix $(BIN), $(SRCS:.c=.o))
LIBFT		=	$(INC)libft/libft.a
C			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3

all			:	$(LIBFT) $(NAME)
$(BIN)%.o	:	$(SRC)%.c
				@ $(C) $(CFLAGS) -c -o $@ $^ -I$(INC)
%.a			:
				@ make -C $(dir $@)
$(NAME)		:	$(OBJS)
				@ $(C) $(CFLAGS) -o $@ $^ -L$(dir $(LIBFT)) -lft
clean		:
				@ rm -rfv $(OBJS)
fclean		:	clean
				@ rm -rfv $(NAME)
re			:	fclean all
.PHONY		:	all clean fclean re
