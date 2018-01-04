# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 09:30:47 by wnoth             #+#    #+#              #
#    Updated: 2017/12/11 10:21:32 by wnoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = src/draw.c \
	   src/setup.c \
	   src/hook.c \
	   src/key.c \
	   src/color.c \
	   src/dot_job.c \
	   src/calc_complex.c \
	   src/fractal_mandelbrot.c \
	   src/fractal_julia.c \
	   src/fractal_crackdisappear.c \
	   src/main.c

GCC_FLAG = -Wall -Werror -Wextra

CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: libft $(NAME)

libft:
	@make -C ./libft/

$(%.o): $(%.c)
	@$(CC) -o $@ -c $^

$(NAME): $(OBJS)
	@$(CC) -o $@ $^ -Lminilibx/ -lmlx -framework OPENGL -framework Appkit -Llibft -lft
	@clear
	@printf "fractol : Compilation \e[38;5;2mD\e[0m\e[38;5;3mO\e[0m\e[38;5;12mN\e[0m\e[38;5;5mE\e[0m\e[38;5;15m !\e[0m"

clean:
	@rm -f $(OBJS)

fclean: clean
	@$(RM) -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: libft minilibx all clean fclean re
