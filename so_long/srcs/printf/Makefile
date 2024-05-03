# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciestrad <ciestrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:29:52 by ciestrad          #+#    #+#              #
#    Updated: 2024/04/10 17:29:06 by ciestrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 		libftprintf.a

CC = gcc
FLAGS= 		-Wall -Wextra -Werror

SRCS=		ft_printf.c \
			hex.c \
			char.c \
			adress.c \
			num.c \
			string.c\
			unsigned.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_strlen.c \


OBJS=		$(SRCS:.c=.o)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS) 

$(OBJS): %.o : %.c
	$(CC) $(FLAGS) -c $< -o $@


all:		$(NAME)

clean:
			rm -f $(OBJS)
			
fclean:		clean
			rm -f $(NAME) 

re: 		fclean all

.PHONY: all clean fclean re