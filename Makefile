# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 23:32:25 by dande-je          #+#    #+#              #
#    Updated: 2023/10/14 05:47:04 by dande-je         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#									PATH									   #
#******************************************************************************#

INCLUDES_DIR						:= include/
OBJS_DIR							:= obj/
SRCS_MAIN_DIR						:= src/
SRCS_UTILS_DIR						:= src/utils/
SRCS_SPEC_DIR						:= src/utils/specifier_utils/
SRCS_MAIN_BONUS_DIR					:= bonus/
SRCS_UTILS_BONUS_DIR				:= bonus/utils/
SRCS_COMBINATION_UTILS_BONUS_DIR	:= bonus/utils/combination_utils/
SRCS_SPEC_BONUS_DIR					:= bonus/utils/specifier_utils/

#******************************************************************************#
#								COMPILATION									   #
#******************************************************************************#

CC									:= cc
CFLAGS								?= -Wall -Wextra -Werror -O3
LIB									:= ar -rcs

#******************************************************************************#
#								BASH COMMANDS								   #
#******************************************************************************#

RM									:= rm -rf
MKDIR								:= mkdir -p
MAKE_NOPRINT						:= $(MAKE) --no-print-directory

#******************************************************************************#
#									FILES									   #
#******************************************************************************#

NAME								:= libftprintf.a

HEADER								:= $(addprefix $(INCLUDES_DIR), ft_printf.h)

SRCS_MAIN_FILES						:= ft_printf.c
SRCS_UTILS_FILES					:= ft_line_utils.c
SRCS_SPEC_FILES						:= ft_cast_chr.c\
										ft_cast_str.c\
										ft_cast_hex.c\
										ft_cast_int.c\
										ft_cast_per.c

HEADER_BONUS						:= $(addprefix $(INCLUDES_DIR), ft_printf_bonus.h)

SRCS_MAIN_BONUS_FILES				:= ft_printf_bonus.c
SRCS_UTILS_BONUS_FILES				:= ft_line_utils_bonus.c
SRCS_COMBINATION_UTILS_BONUS_FILES	:= ft_parse_combination.c\
										ft_plus.c\
										ft_space.c\
										ft_minus.c
SRCS_SPEC_BONUS_FILES				:= ft_cast_chr_bonus.c\
										ft_cast_str_bonus.c\
										ft_cast_hex_bonus.c\
										ft_cast_int_bonus.c\
										ft_cast_per_bonus.c

SRCS_MAIN							:= $(addprefix $(SRCS_MAIN_DIR), $(SRCS_MAIN_FILES))
SRCS_UTILS							:= $(addprefix $(SRCS_UTILS_DIR), $(SRCS_UTILS_FILES))
SRCS_SPEC							:= $(addprefix $(SRCS_SPEC_DIR), $(SRCS_SPEC_FILES))

SRCS_MAIN_BONUS						:= $(addprefix $(SRCS_MAIN_BONUS_DIR), $(SRCS_MAIN_BONUS_FILES))
SRCS_UTILS_BONUS					:= $(addprefix $(SRCS_UTILS_BONUS_DIR), $(SRCS_UTILS_BONUS_FILES))
SRCS_COMBINATION_UTILS_BONUS		:= $(addprefix $(SRCS_COMBINATION_UTILS_BONUS_DIR), $(SRCS_COMBINATION_UTILS_BONUS_FILES))
SRCS_SPEC_BONUS						:= $(addprefix $(SRCS_SPEC_BONUS_DIR), $(SRCS_SPEC_BONUS_FILES))

OBJS_MAIN							:= $(SRCS_MAIN:$(SRCS_MAIN_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_UTILS							:= $(SRCS_UTILS:$(SRCS_UTILS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_SPEC							:= $(SRCS_SPEC:$(SRCS_SPEC_DIR)%.c=$(OBJS_DIR)%.o)

OBJS_MAIN_BONUS						:= $(SRCS_MAIN_BONUS:$(SRCS_MAIN_BONUS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_UTILS_BONUS					:= $(SRCS_UTILS_BONUS:$(SRCS_UTILS_BONUS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_COMBINATION_UTILS_BONUS		:= $(SRCS_COMBINATION_UTILS_BONUS:$(SRCS_COMBINATION_UTILS_BONUS_DIR)%.c=$(OBJS_DIR)%.o)
OBJS_SPEC_BONUS						:= $(SRCS_SPEC_BONUS:$(SRCS_SPEC_BONUS_DIR)%.c=$(OBJS_DIR)%.o)

OBJS								:= $(OBJS_MAIN) $(OBJS_UTILS) $(OBJS_SPEC)
OBJS_BONUS							:= $(OBJS_MAIN_BONUS) $(OBJS_UTILS_BONUS) $(OBJS_COMBINATION_UTILS_BONUS) $(OBJS_SPEC_BONUS)

ifdef WITH_BONUS
	OBJS							= $(OBJS_BONUS)
	HEADER							= $(HEADER_BONUS)
endif

#******************************************************************************#
#									TARGETS									   #
#******************************************************************************#

all:								$(NAME)

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

$(OBJS_DIR)%.o : $(SRCS_MAIN_BONUS_DIR)%.c
										@$(MKDIR) $(OBJS_DIR)
										$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
										$(LIB) $(NAME) $@
$(OBJS_DIR)%.o : $(SRCS_UTILS_BONUS_DIR)%.c
										@$(MKDIR) $(OBJS_DIR)
										$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
										$(LIB) $(NAME) $@
$(OBJS_DIR)%.o : $(SRCS_COMBINATION_UTILS_BONUS_DIR)%.c
										@$(MKDIR) $(OBJS_DIR)
										$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
										$(LIB) $(NAME) $@
$(OBJS_DIR)%.o : $(SRCS_SPEC_BONUS_DIR)%.c
										@$(MKDIR) $(OBJS_DIR)
										$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
										$(LIB) $(NAME) $@

$(NAME):							$(OBJS)

bonus:
										$(MAKE_NOPRINT) WITH_BONUS=TRUE

clean:
										$(RM) $(OBJS_DIR)

fclean:								clean
										$(RM) $(NAME)

re:									fclean all

.PHONY:								all clean fclean re bonus
