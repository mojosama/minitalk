NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror 

HEADERS = minitalk.h

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT =$(SRC_CLIENT:.c=.o)
OBJ_SERVER =$(SRC_SERVER:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME_CLIENT) $(NAME_SERVER)

%.o: %.c $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@$(LIBFT_MAKE)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(LIBFT_MAKE) fclean

re: fclean all

.PHONY:  all clean fclean re
