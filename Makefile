# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 18:02:18 by iskaraag          #+#    #+#              #
#    Updated: 2024/08/27 18:02:21 by iskaraag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c error_handler.c makestack.c stack_utils.c tiny_sort.c commands.c commands_r.c push_swap.c push_swap_utils.c
OBJ = $(SRC:.c=.o)
CC = gcc -Wall -Werror -Wextra
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
RM = rm -f
NAME = push_swap

all: $(NAME)

$(LIBFT):
		$(MAKE) -C libft

$(PRINTF):
		$(MAKE) -C ft_printf

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
				$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)


clean:
		$(MAKE) clean -C libft
		$(MAKE) clean -C ft_printf
		$(RM) $(OBJ)

fclean: clean
		$(MAKE) fclean -C libft
		$(MAKE) fclean -C ft_printf
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
