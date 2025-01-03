NAME = pipex

CC = cc

CFLAGS = -Wall -Werorr -Wextra

SRC = pipex.c pipex_utils.c /libft/libft.a

RM = rm -rf

OBJ = ${SRC:.c=.o}

${NAME}:
	make all -C libft
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

all : ${NAME}

fclean : clean
	${RM} ${NAME}
	make fclean -C libft

clean :
	${RM} ${NAME}
	make clean -C libft

re : fclean all

.PHONY: all clean fclean re