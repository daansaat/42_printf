NAME 	= 	libftprintf.a
CFLAGS 	= 	-Wall -Werror -Wextra
SRCS 	= 	ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_str.c \
			ft_printf.c
OBJS 	= 	$(SRCS:.c=.o)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

all:	$(NAME)

%.o:	%.c
		gcc $(FLAGS) -o $@ -c $<

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all