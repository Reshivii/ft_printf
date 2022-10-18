# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 14:09:18 by aburnott          #+#    #+#              #
#    Updated: 2022/10/18 20:40:34 by aburnott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_utils.c ft_hexa.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	gcc -c $(CFLAGS) $?

clean:
	rm -f $(OBJS) 

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re