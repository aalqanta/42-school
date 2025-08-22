# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalqanta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 00:15:10 by aalqanta          #+#    #+#              #
#    Updated: 2025/05/07 00:15:16 by aalqanta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER		= server
NAME_CLIENT		= client
NAME_SERVERB	= server_bonus
NAME_CLIENTB	= client_bonus

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

SRCS_SERVER		= server.c
SRCS_CLIENT		= client.c
SRCS_SERVERB	= server_bonus.c
SRCS_CLIENTB	= client_bonus.c

OBJS_SERVER		= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT		= $(SRCS_CLIENT:.c=.o)
OBJS_SERVERB	= $(SRCS_SERVERB:.c=.o)
OBJS_CLIENTB	= $(SRCS_CLIENTB:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVERB) $(NAME_CLIENTB)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

$(NAME_SERVERB): $(OBJS_SERVERB)
	$(CC) $(CFLAGS) -o $(NAME_SERVERB) $(OBJS_SERVERB)

$(NAME_CLIENTB): $(OBJS_CLIENTB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENTB) $(OBJS_CLIENTB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVERB) $(OBJS_CLIENTB)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVERB) $(NAME_CLIENTB)

re: fclean all

.PHONY: all bonus clean fclean re

