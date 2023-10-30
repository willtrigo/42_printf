# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:32:25 by dande-je          #+#    #+#              #
#    Updated: 2023/10/30 10:09:54 by dande-je         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#									PATH									   #
#******************************************************************************#

INCLUDES_DIR				:= include/
OBJS_DIR					:= obj/
SRCS_MAIN_DIR				:= src/
SRCS_UTILS_DIR				:= src/utils/
SRCS_SPEC_DIR				:= src/utils/specifier_utils/
SRCS_MAIN_BONUS_DIR			:= bonus/
SRCS_UTILS_BONUS_DIR		:= bonus/utils/
SRCS_COMBINATION_BONUS_DIR	:= bonus/utils/combination_utils/
SRCS_SPEC_BONUS_DIR			:= bonus/utils/specifier_utils/

#******************************************************************************#
#								COMPILATION									   #
#******************************************************************************#

CC							:= cc
CFLAGS						?= -Wall -Wextra -Werror -O3
LIB							:= ar -rcs

#******************************************************************************#
#								BASH COMMANDS								   #
#******************************************************************************#

RM							:= rm -rf
MKDIR						:= mkdir -p
MAKE_NOPRINT				:= $(MAKE) --no-print-directory
SLEEP						:= sleep 0.3

#******************************************************************************#
#									FILES									   #
#******************************************************************************#

NAME						:= libftprintf.a

HEADER						:= $(addprefix $(INCLUDES_DIR), ft_printf.h)

SRCS_FILES					+= $(addprefix $(SRCS_MAIN_DIR), ft_printf.c)
SRCS_FILES					+= $(addprefix $(SRCS_UTILS_DIR), ft_line_utils.c)
SRCS_FILES					+= $(addprefix $(SRCS_SPEC_DIR), ft_specifier.c\
								ft_cast_chr.c\
								ft_cast_str.c\
								ft_cast_hex.c\
								ft_cast_int.c\
								ft_cast_per.c)

HEADER_BONUS				:= $(addprefix $(INCLUDES_DIR), ft_printf_bonus.h)

SRCS_BONUS_FILES			+= $(addprefix $(SRCS_MAIN_BONUS_DIR), ft_printf_bonus.c)
SRCS_BONUS_FILES			+= $(addprefix $(SRCS_UTILS_BONUS_DIR), ft_line_utils_bonus.c)
SRCS_BONUS_FILES			+= $(addprefix $(SRCS_COMBINATION_BONUS_DIR), ft_parse_combination.c\
								ft_parse_hash.c\
								ft_parse_plus.c\
								ft_parse_space.c\
								ft_parse_minus.c\
								ft_parse_width.c\
								ft_parse_zero.c\
								ft_parse_precision.c\
								ft_combination_chr.c\
								ft_combination_str.c\
								ft_combination_hex.c\
								ft_combination_hex_math.c\
								ft_combination_int.c)
SRCS_BONUS_FILES			+= $(addprefix $(SRCS_SPEC_BONUS_DIR), ft_specifier_bonus.c\
								ft_cast_chr_bonus.c\
								ft_cast_str_bonus.c\
								ft_cast_hex_bonus.c\
								ft_cast_int_bonus.c\
								ft_cast_per_bonus.c)

OBJS						+= $(SRCS_FILES:%.c=$(OBJS_DIR)%.o)

OBJS_BONUS					+= $(SRCS_BONUS_FILES:%.c=$(OBJS_DIR)%.o)

ifdef WITH_BONUS
	OBJS					= $(OBJS_BONUS)
	HEADER					= $(HEADER_BONUS)
endif

#******************************************************************************#
#								OUTPUTS MESSAGES							   #
#******************************************************************************#

CLEAN_MESSAGE				:= Objects deleted
FCLEAN_MESSAGE				:= Library deleted
LIB_MESSAGE					:= Library created
COMP						:= Compiling library

#******************************************************************************#
#									TARGETS									   #
#******************************************************************************#

all:						$(NAME)

$(OBJS_DIR)%.o: %.c
								@$(MKDIR) $(dir $@)
								@$(eval COUNT=$(shell expr $(COUNT) + 1))
								@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
								@printf "$(COMP) %d%%\r" $$(echo $$(($(COUNT) * 100 / $(words $(OBJS)))))

$(NAME):					$(OBJS)
								@$(LIB) $(NAME) $(OBJS) $@
								@$(SLEEP)
								@printf "\n$(LIB_MESSAGE)\n"

bonus:
								@$(MAKE_NOPRINT) WITH_BONUS=TRUE

clean:
								@$(RM) $(OBJS_DIR)
								@$(SLEEP)
								@printf "$(CLEAN_MESSAGE)\n"

fclean:						clean
								@$(RM) $(NAME)
								@$(SLEEP)
								@printf "$(FCLEAN_MESSAGE)\n"

re:							fclean all

.PHONY:						all clean fclean re bonus
