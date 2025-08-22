NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -Iinclude

SRCS = hooks.c init.c main.c pixel.c render.c utils.c
OBJS = $(SRCS:.c=.o)



MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME) $(MLX)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re