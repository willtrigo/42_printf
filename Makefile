# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:32:25 by dande-je          #+#    #+#              #
#    Updated: 2023/10/02 04:36:40 by dande-je         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRCS := ft_printf.c

HEADER := ft_printf.h

SRCS_BONUS := 

HEADER_BONUS := 

OBJS := $(SRCS:.c=.o)

OBJS_BONUS := $(SRCS_BONUS:.c=.o)

CC := cc

CFLAGS := -Wall -Wextra -Werror

AR := ar -rcs

RM := rm -rf

ifdef WITH_BONUS
	OBJS = $(OBJS_BONUS)
	HEADER = $(HEADER_BONUS)
endif

all:	$(NAME)

%.o:%.c
	$(CC) $(SFLAGS) $(CFLAGS) -I $(HEADER) -c $< -o $@
	$(AR) $(NAME) $@

$(NAME):	$(OBJS)

bonus:
	@make WITH_BONUS=TRUE --no-print-directory

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
