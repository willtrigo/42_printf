# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:32:25 by dande-je          #+#    #+#              #
#    Updated: 2023/10/07 23:54:42 by dande-je         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#									PATH									   #
#******************************************************************************#

INCLUDES_DIR			:= include/
OBJS_DIR				:= obj/
SRCS_MAIN_DIR			:= src/
SRCS_UTILS_DIR			:= src/utils/
SRCS_SPECIFIER_DIR		:= src/utils/specifier_utils/

#******************************************************************************#
#								COMPILATION									   #
#******************************************************************************#

CC						:= cc
CFLAGS					:= -Wall -Wextra -Werror
LIB						:= ar -rcs

#******************************************************************************#
#								BASH COMMANDS								   #
#******************************************************************************#

RM						:= rm -rf
MKDIR					:= mkdir -p
MAKE_NOPRINT			:= $(MAKE) --no-print-directory

#******************************************************************************#
#									FILES									   #
#******************************************************************************#

NAME					:= libftprintf.a

HEADER					:= $(addprefix $(INCLUDES_DIR), ft_printf.h)
SRCS_MAIN_FILES			:= ft_printf.c
SRCS_UTILS_FILES		:= ft_line_utils.c
SRCS_SPECIFIER_FILES	:= ft_cast_char.c\
							ft_cast_str.c\
							ft_cast_hex.c\
							ft_cast_int.c

HEADER_BONUS			:=
SRCS_FILES_BONUS		:=

SRCS_MAIN				:= $(addprefix $(SRCS_MAIN_DIR), $(SRCS_MAIN_FILES))
SRCS_UTILS				:= $(addprefix $(SRCS_UTILS_DIR), $(SRCS_UTILS_FILES))
SRCS_SPECIFIER			:= $(addprefix $(SRCS_SPECIFIER_DIR), $(SRCS_SPECIFIER_FILES))

OBJS_MAIN				:= $(SRCS_MAIN:$(SRCS_MAIN_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_UTILS				:= $(SRCS_UTILS:$(SRCS_UTILS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_SPECIFIER			:= $(SRCS_SPECIFIER:$(SRCS_SPECIFIER_DIR)%.c=$(OBJS_DIR)%.o)

OBJS					:= $(OBJS_MAIN) $(OBJS_UTILS) $(OBJS_SPECIFIER)
SRCS_BONUS				:= $(addprefix $(SRCS_DIR), $(SRCS_FILES_BONUS))
OBJS_BONUS				:= $(SRCS_BONUS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

ifdef WITH_BONUS
	OBJS				= $(OBJS_BONUS)
	HEADER				= $(HEADER_BONUS)
endif

#******************************************************************************#
#									TARGETS									   #
#******************************************************************************#

all:					$(NAME)

$(OBJS_DIR)%.o : $(SRCS_MAIN_DIR)%.c
							@$(MKDIR) $(OBJS_DIR)
							$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
							$(LIB) $(NAME) $@

$(OBJS_DIR)%.o : $(SRCS_UTILS_DIR)%.c
							@$(MKDIR) $(OBJS_DIR)
							$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
							$(LIB) $(NAME) $@

$(OBJS_DIR)%.o : $(SRCS_SPECIFIER_DIR)%.c
							@$(MKDIR) $(OBJS_DIR)
							$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
							$(LIB) $(NAME) $@

$(NAME):				$(OBJS)

bonus:
							$(MAKE_NOPRINT) WITH_BONUS=TRUE

clean:
							$(RM) $(OBJS_DIR)

fclean:					clean
							$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re bonus
