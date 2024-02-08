# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 11:01:46 by dgomez-b          #+#    #+#              #
#    Updated: 2024/02/08 19:27:07 by dgomez-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
BIN			=	./.bin/
SRC			=	./src/
INC			=	./includes/
SRCS		=	main.c \
				freemat.c \
				error.c \
				paths.c \
				process.c
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
