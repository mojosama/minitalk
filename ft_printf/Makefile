NAME = ft_printf

CC = cc

CFLAGS = -Wall -Wextra -Werror 

AR = ar

ARFLAGS = rcs

HEADERS = ft_printf.h

SRCS = ft_printf.c print_formats.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re