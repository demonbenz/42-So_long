# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otangkab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 17:19:05 by otangkab          #+#    #+#              #
#    Updated: 2023/01/12 11:09:59 by otangkab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.c ft_strnstr.c ft_bzero.c ft_calloc.c ft_strdup.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \

OBJS	= $(SRCS:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -c
NAME	= libft.a

all: $(NAME) 

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
