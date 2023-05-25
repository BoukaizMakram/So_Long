NAME = so_long.a

CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -lmlx -framework appkit -framework openGl

RM = rm -f

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c \
	backtracking.c draw.c movement.c so_long.c parcing.c

OBJ = ${SRC:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ) so_long.h
	@ar rc $(NAME) $(OBJ)
	@$(CC) $(CFLAGS) $(FRAMEWORK) $(NAME) -o so_long


clean :
	@${RM} ${OBJ} ${NAME}

fclean : clean
	@${RM} so_long

re : fclean all