# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:32:25 by dande-je          #+#    #+#              #
#    Updated: 2023/11/07 20:13:45 by dande-je         ###   ########.fr        #
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
SRCS_PARSE_BONUS_DIR		:= bonus/utils/parse_utils/
SRCS_COMBINATION_BONUS_DIR	:= bonus/utils/parse_utils/combination_utils/
SRCS_SPEC_BONUS_DIR			:= bonus/utils/specifier_utils/

#******************************************************************************#
#								COMPILATION									   #
#******************************************************************************#

CC							:= cc
CFLAGS						?= -Wall -Wextra -Werror -O1 -fno-omit-frame-pointer -g
LDFLAGS						:= -fsanitize=address
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

HEADER						:= $(INCLUDES_DIR)

SRCS_FILES					+= $(addprefix $(SRCS_MAIN_DIR), ft_printf.c)
SRCS_FILES					+= $(addprefix $(SRCS_UTILS_DIR), ft_line_utils.c)
SRCS_FILES					+= $(addprefix $(SRCS_SPEC_DIR), ft_specifier.c\
								ft_cast_chr.c\
								ft_cast_str.c\
								ft_cast_hex.c\
								ft_cast_int.c\
								ft_cast_per.c)

HEADER_BONUS				:= $(INCLUDES_DIR)

SRCS_BONUS_FILES			+= $(addprefix $(SRCS_MAIN_BONUS_DIR), ft_printf_bonus.c)
SRCS_BONUS_FILES			+= $(addprefix $(SRCS_UTILS_BONUS_DIR), ft_line_utils_bonus.c\
								ft_str_utils.c\
								ft_nbr_utils.c)
SRCS_BONUS_FILES			+= $(addprefix $(SRCS_PARSE_BONUS_DIR), ft_parse_combination.c\
								ft_parse_hash.c\
								ft_parse_plus.c\
								ft_parse_space.c\
								ft_parse_minus.c\
								ft_parse_width.c\
								ft_parse_zero.c\
								ft_parse_precision.c)
SRCS_BONUS_FILES			+= $(addprefix $(SRCS_COMBINATION_BONUS_DIR), ft_combination_chr.c\
								ft_combination_str.c\
								ft_combination_str_math_null.c\
								ft_combination_hex.c\
								ft_combination_hex_math.c\
								ft_combination_int.c\
								ft_combination_int_math.c\
								ft_combination_int_math_zero.c\
								ft_combination_int_math_width.c\
								ft_combination_int_math_minus.c\
								ft_combination_str_math.c)
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
	LIB_MESSAGE				= $(LIB_MESSAGE_BONUS)
	COMP					= $(COMP_BONUS)
endif

#******************************************************************************#
#								OUTPUTS MESSAGES							   #
#******************************************************************************#

CLEAN_MESSAGE				:= Printf objects deleted
FCLEAN_MESSAGE				:= Library printf deleted
LIB_MESSAGE					= Printf library created
LIB_MESSAGE_BONUS			= Printf library bonus created
COMP						= Compiling printf library
COMP_BONUS					= Compiling printf library bonus

#******************************************************************************#
#									TARGETS									   #
#******************************************************************************#

all:						$(NAME)

$(OBJS_DIR)%.o: %.c
								@$(MKDIR) $(dir $@)
								@$(eval COUNT=$(shell expr $(COUNT) + 1))
								@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@ $(LDFLAGS)
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
