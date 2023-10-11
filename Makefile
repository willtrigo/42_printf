# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:32:25 by dande-je          #+#    #+#              #
#    Updated: 2023/10/11 07:41:33 by dande-je         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#									PATH									   #
#******************************************************************************#

INCLUDES_DIR			:= include/
OBJS_DIR				:= obj/
SRCS_MAIN_DIR			:= src/
SRCS_UTILS_DIR			:= src/utils/
SRCS_SPEC_DIR			:= src/utils/specifier_utils/
SRCS_MAIN_BNS_DIR		:= bonus/
SRCS_UTILS_BNS_DIR		:= bonus/utils/
SRCS_SPEC_BNS_DIR		:= bonus/utils/specifier_utils/

#******************************************************************************#
#								COMPILATION									   #
#******************************************************************************#

CC						:= cc
CFLAGS					?= -Wall -Wextra -Werror -O3
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
SRCS_SPEC_FILES			:= ft_cast_c.c\
							ft_cast_str.c\
							ft_cast_hex.c\
							ft_cast_int.c

HEADER_BNS				:= $(addprefix $(INCLUDES_DIR), ft_printf_bonus.h)

SRCS_MAIN_BNS_FILES		:= ft_printf_bonus.c
SRCS_UTILS_BNS_FILES	:= ft_line_utils_bonus.c
SRCS_SPEC_BNS_FILES		:= ft_cast_c_bonus.c\
							ft_cast_str_bonus.c\
							ft_cast_hex_bonus.c\
							ft_cast_int_bonus.c

SRCS_MAIN				:= $(addprefix $(SRCS_MAIN_DIR), $(SRCS_MAIN_FILES))
SRCS_UTILS				:= $(addprefix $(SRCS_UTILS_DIR), $(SRCS_UTILS_FILES))
SRCS_SPEC				:= $(addprefix $(SRCS_SPEC_DIR), $(SRCS_SPEC_FILES))

SRCS_MAIN_BNS			:= $(addprefix $(SRCS_MAIN_BNS_DIR), $(SRCS_MAIN_BNS_FILES))
SRCS_UTILS_BNS			:= $(addprefix $(SRCS_UTILS_BNS_DIR), $(SRCS_UTILS_BNS_FILES))
SRCS_SPEC_BNS			:= $(addprefix $(SRCS_SPEC_BNS_DIR), $(SRCS_SPEC_BNS_FILES))

OBJS_MAIN				:= $(SRCS_MAIN:$(SRCS_MAIN_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_UTILS				:= $(SRCS_UTILS:$(SRCS_UTILS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_SPEC				:= $(SRCS_SPEC:$(SRCS_SPEC_DIR)%.c=$(OBJS_DIR)%.o)

OBJS_MAIN_BNS			:= $(SRCS_MAIN_BNS:$(SRCS_MAIN_BNS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_UTILS_BNS			:= $(SRCS_UTILS_BNS:$(SRCS_UTILS_BNS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_SPEC_BNS			:= $(SRCS_SPEC_BNS:$(SRCS_SPEC_BNS_DIR)%.c=$(OBJS_DIR)%.o)

OBJS					:= $(OBJS_MAIN) $(OBJS_UTILS) $(OBJS_SPEC)
OBJS_BNS				:= $(OBJS_MAIN_BNS) $(OBJS_UTILS_BNS) $(OBJS_SPEC_BNS)

ifdef WITH_BNS
	OBJS				= $(OBJS_BNS)
	HEADER				= $(HEADER_BNS)
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
$(OBJS_DIR)%.o : $(SRCS_SPEC_DIR)%.c
							@$(MKDIR) $(OBJS_DIR)
							$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
							$(LIB) $(NAME) $@

$(OBJS_DIR)%.o : $(SRCS_MAIN_BNS_DIR)%.c
							@$(MKDIR) $(OBJS_DIR)
							$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
							$(LIB) $(NAME) $@
$(OBJS_DIR)%.o : $(SRCS_UTILS_BNS_DIR)%.c
							@$(MKDIR) $(OBJS_DIR)
							$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
							$(LIB) $(NAME) $@
$(OBJS_DIR)%.o : $(SRCS_SPEC_BNS_DIR)%.c
							@$(MKDIR) $(OBJS_DIR)
							$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
							$(LIB) $(NAME) $@

$(NAME):				$(OBJS)

bonus:
							$(MAKE_NOPRINT) WITH_BNS=TRUE

clean:
							$(RM) $(OBJS_DIR)

fclean:					clean
							$(RM) $(NAME)

re:						fclean all

.PHONY:					all clean fclean re bonus
