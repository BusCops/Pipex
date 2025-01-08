NAME = pipex

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = pipex.c pipex_utils.c

RM = rm -rf

OBJ = ${SRC:.c=.o}

LIBFT = libft/libft.a

${NAME}: ${SRC}
	make all -C libft
	${CC} ${CFLAGS} ${SRC} ${LIBFT} -o ${NAME}

all : ${NAME}

fclean : clean
	${RM} ${NAME}
	make fclean -C libft

clean :
	${RM} ${NAME}
	make clean -C libft

re : fclean all

.PHONY: all clean fclean re