NAME= libftprintf.a

GCC= gcc -Wall -Wextra -Werror -I./include

SRC= ft_printf.c ft_printf_utils.c ft_printcspdi.c ft_printuxX.c

OBJ= $(SRC:.c=.o)

RM= rm -f

%.o: %.c
	$(GCC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
