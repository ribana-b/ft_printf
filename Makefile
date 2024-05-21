# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 12:27:33 by ribana-b          #+#    #+# Malaga       #
#    Updated: 2024/05/21 12:31:43 by ribana-b         ###   ########.com       #
#                                                                              #
# **************************************************************************** #


# @--------------------------------------------------------------------------@ #
# |                                 Colors                                   | #
# @--------------------------------------------------------------------------@ #

T_BLACK = \033[30m
T_RED = \033[31m
T_GREEN = \033[32m
T_YELLOW = \033[33m
T_BLUE = \033[34m
T_MAGENTA = \033[35m
T_CYAN = \033[36m
T_WHITE = \033[37m

BOLD = \033[1m
ITALIC = \033[3m
UNDERLINE = \033[4m
STRIKETHROUGH = \033[9m

CLEAR_LINE = \033[1F\r\033[2K

RESET = \033[0m

# @--------------------------------------------------------------------------@ #
# |                                 Macros                                   | #
# @--------------------------------------------------------------------------@ #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
UTILS_DIR = utils/

SRC_FILES = ft_printf.c
UTILS_FILES = ft_putchar.c ft_putnbr.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR), $(UTILS_FILES))
OBJ_SRC = $(SRC:.c=.o)
OBJ_UTILS = $(UTILS:.c=.o)

COMPILE_MSG = @echo "$(CLEAR_LINE)🧩 🦔 $(T_WHITE)$(BOLD)Compiling $<...$(RESET)"
OBJ_MSG = @echo "✅ 🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_GREEN)created successfully!$(RESET)"
OUTPUT_MSG = @echo "✅ 🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_GREEN)created successfully!$(RESET)"
CLEAN_MSG = @echo "🗑️  🦔 $(T_YELLOW)$(BOLD)Objects $(RESET)$(T_RED)destroyed successfully!$(RESET)"
FCLEAN_MSG = @echo "🗑️  🦔 $(T_MAGENTA)$(BOLD)$(NAME) $(RESET)$(T_RED)destroyed successfully!$(RESET)"

# @--------------------------------------------------------------------------@ #
# |                                 Targets                                  | #
# @--------------------------------------------------------------------------@ #

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_UTILS)
	$(OBJ_MSG)
	@ar rcs $(NAME) $(OBJ_SRC) $(OBJ_UTILS)
	$(OUTPUT_MSG)

%.o: %.c
	$(COMPILE_MSG)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_SRC) $(OBJ_UTILS)
	$(CLEAN_MSG)

fclean: clean
	@rm -f $(NAME)
	$(FCLEAN_MSG)

re:
	@make -s fclean
	@echo
	@make -s all

.PHONY: all clean fclean re
