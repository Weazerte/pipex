# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:26:20 by eaubry            #+#    #+#              #
#    Updated: 2023/04/11 15:16:54 by eaubry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =	ft_pipex.c \
				ft_cmd.c \
				ft_exit_msg.c \
				ft_childs.c \
				ft_free.c

INC    =	pipex.h

NAME    =	pipex

OBJS    =	${SRCS:.c=.o}

CFLAGS    =    -Wall -Wextra -Werror -g

CC	= 	cc

all:	${NAME}

.c.o:	${INC}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	libft/libft.a ${OBJS}
	${CC} ${OBJS} ${CFLAGS} -Llibft -lft -o ${NAME} 

clean:
	rm -f ${OBJS}
	make -C libft clean

fclean:	clean
	rm -f ${NAME}
	make -C libft fclean


re:	fclean all

.PHONY:	all clean fclean re bonus

libft/libft.a:
	make -C libft
	
