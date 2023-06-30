NAME = libftprintf.a

COMPILATOR = gcc

FILES =	ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c

FLAGS = -Wall -Wextra -Werror -c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(COMPILATOR) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
