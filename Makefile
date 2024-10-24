# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodordev <dodordev@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 14:34:50 by j                 #+#    #+#              #
#    Updated: 2024/10/21 13:05:14 by dodordev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

SRCS = src/main.c src/tokenizer.c src/exec.c src/check_find_path.c src/builtins/builtins.c src/utils.c src/parse.c src/redirections.c src/signals.c src/builtins/ft_echo.c src/builtins/ft_cd.c src/builtins/ft_pwd.c src/builtins/ft_export.c src/builtins/ft_unset.c src/builtins/ft_env.c src/builtins/ft_exit.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -I./include
LIBS = -lreadline

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

