# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esobrinh <esobrinh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 19:28:32 by esobrinh          #+#    #+#              #
#    Updated: 2022/11/10 16:08:57 by esobrinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PATH_SRCS = ./sources/
PATH_INCLUDES = ./includes/
PATH_OBJS = ./objects/

CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix $(PATH_SRCS),\
				ft_printf.c \
				ft_printf_utils.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

INCLUDES = -I $(PATH_INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	mkdir -p $(PATH_OBJS)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			rm -rf $(PATH_OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re 