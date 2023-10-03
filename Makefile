# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:32:25 by dande-je          #+#    #+#              #
#    Updated: 2023/10/03 00:53:53 by dande-je         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

# PATH
SRCS_DIR			:= src/
INCLUDES_DIR		:= include/
OBJS_DIR			:= obj/

# COMPILATION
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror
AR					:= ar -rcs

# BASH COMMANDS
RM					:= rm -rf
MKDIR				:= mkdir -p
MAKE_NOPRINT		:= $(MAKE) --no-print-directory

# FILES
NAME				:= libftprintf.a

HEADER				:= $(addprefix $(INCLUDES_DIR), ft_printf.h)
SRCS_FILES			:= ft_printf.c

HEADER_BONUS		:=
SRCS_FILES_BONUS	:=

SRCS				:= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS				:= $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
SRCS_BONUS			:= $(addprefix $(SRCS_DIR), $(SRCS_FILES_BONUS))
OBJS_BONUS			:= $(SRCS_BONUS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

ifdef WITH_BONUS
	OBJS			= $(OBJS_BONUS)
	HEADER			= $(HEADER_BONUS)
endif

# TARGETS
all:				$(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
						@$(MKDIR) $(OBJS_DIR)
						$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
						$(AR) $(NAME) $@

$(NAME):			$(OBJS)

bonus:
						$(MAKE_NOPRINT) WITH_BONUS=TRUE

clean:
						$(RM) $(OBJS_DIR)

fclean:				clean
						$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re bonus
