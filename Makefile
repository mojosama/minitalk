NAME_CLIENT = client

NAME_SERVER = server

CC = cc

CFLAGS = -Wall -Wextra -Werror 

HEADERS = minitalk.h

SRCS = utils.c ft_printf/ft_printf.c ft_printf/print_formats.c

SRC_CLIENT = client.c

SRC_SERVER = server.c

OBJS =$(SRCS:.c=.o)

OBJ_CLIENT =$(SRC_CLIENT:.c=.o)

OBJ_SERVER =$(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJS)
	$(CC) $(OBJ_CLIENT) $(OBJS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(OBJS)
	$(CC) $(OBJ_SERVER) $(OBJS) -o $(NAME_SERVER)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SERVER)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)

re: fclean all

.PHONY:  all clean fclean re