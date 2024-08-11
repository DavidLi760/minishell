NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
LFLAGS	= -lreadline
SRC		= main.c
OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
	rm -rf $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJ)

.PHONY : clean fclean re all
