NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
LFLAGS	= -lreadline -lwaitpid
SRCS	=	main.c
OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJS)

.PHONY : clean fclean all re
