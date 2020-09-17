NAME	=	do-op

CC		=	gcc
CFLAGS	= 	-c -Wall -Wextra -Werror
SRCS	= 	main.c operators.c output.c
INCS	=	operators.h output.h
OBJS	=	$(SRCS:.c=.o)

$(NAME):
		$(CC) $(CFLAGS) -I $(INCS) $(SRCS)
		$(CC) $(OBJS) -o $(NAME)

all:	$(NAME)
clean:
		rm -f $(OBJS)
fclean:	clean
		rm -f $(NAME)
.PHONY:	all clean fclean
