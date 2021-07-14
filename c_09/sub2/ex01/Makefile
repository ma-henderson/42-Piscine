SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	= ${SRCS:.c=.o} 
NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

libft.a:	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}
c.o.:	
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}
all:		${NAME}

clean:
			rm -f ${OBJS}
fclean:		clean
			rm -f ${NAME}
re:			fclean all
