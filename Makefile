# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 22:56:32 by vnazioze          #+#    #+#              #
#    Updated: 2022/01/18 00:10:14 by vnazioze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	so_long
NAME_BONUS		:=	so_long_bonus

CC				:=	gcc

CFLAGS			:=	-Wall -Werror -Wextra
LIB				:=	-lmlx -lXext -lX11

LIBFT			:=	./libft/libft.a

DIR			:=	./src/
DIR_BONUS	:=	./src_bonus/

SRC		:=		$(addprefix $(DIR),	\
				verify_error.c		\
				exit_free.c			\
				move.c				\
				render_game.c		\
				so_long.c			\
				read_map.c			\
				)
SRC_BONUS =		$(addprefix $(DIR_BONUS),\
				verify_error.c			\
				exit_free.c				\
				move.c					\
				render_game.c			\
				so_long.c				\
				read_map.c				\
				)

OBJS		:=	${SRC:%.c=%.o}
OBJS_BONUS	:=	${SRC_BONUS:.c=.o}

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME): 		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBFT)

bonus: 			$(NAME_BONUS)

$(NAME_BONUS):	$(LIBFT) $(OBJS_BONUS)
				$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIB) $(LIBFT)

$(LIBFT):
				make bonus -C ./libft

clean:
				rm -f $(OBJS) $(OBJS_BONUS)
				make clean -C ./libft

fclean:			clean
				rm -f $(NAME) $(NAME_BONUS)
				make fclean -C ./libft

re:				fclean all

rebonus:		fclean bonus

.PHONY: 		all, clean, fclean, re, bonus, rebonus