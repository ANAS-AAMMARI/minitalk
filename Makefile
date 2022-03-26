# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 22:18:14 by aaammari          #+#    #+#              #
#    Updated: 2022/03/26 01:11:54 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

HEADER = minitalk.h

SERVER_SRCS = server.c ft_itoa.c ft_strlen.c ft_strdup.c ft_strlcpy.c

CLIENT_SRCS = client.c ft_atoi.c	

SERVER_BONUS = server_bonus.c ft_itoa.c ft_strlen.c ft_strdup.c ft_strlcpy.c

CLIENT_BONUS = client_bonus.c ft_atoi.c

SERVER_OBJS_BN = ${SERVER_BONUS:.c=.o}
CLIENT_OBJS_BN = ${CLIENT_BONUS:.c=.o}

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: server client

bonus: server_bonus client_bonus

client: ${CLIENT_OBJS}
	@$(CC) ${CFLAGS} ${CLIENT_OBJS} -o client

server:${SERVER_OBJS}
	@${CC} ${CFLAGS} ${SERVER_OBJS} -o server

client_bonus:${CLIENT_OBJS_BN}
	@$(CC) ${CFLAGS} ${CLIENT_OBJS_BN} -o client

server_bonus:${SERVER_OBJS_BN}
	@${CC} ${CFLAGS} ${SERVER_OBJS_BN} -o server

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) ${CLIENT_OBJS_BN} ${SERVER_OBJS_BN}

fclean: clean
	@$(RM) client server

re:fclean all