NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror 

HEADERS = minitalk.h

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT =$(SRC_CLIENT:.c=.o)
OBJ_SERVER =$(SRC_SERVER:.c=.o)

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a
PRINTF_MAKE = $(MAKE) -C $(PRINTF_DIR)

all: $(NAME_CLIENT) $(NAME_SERVER)

%.o: %.c $(HEADERS) $(PRINTF)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_CLIENT): $(OBJ_CLIENT) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_SERVER): $(OBJ_SERVER) $(PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(PRINTF):
	@$(PRINTF_MAKE)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(PRINTF_MAKE) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(PRINTF_MAKE) fclean

re: fclean all

.PHONY:  all client server clean fclean re
