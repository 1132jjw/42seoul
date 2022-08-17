CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCS = -I ./includes/

SRC_DIR = ./srcs/
SRCS = main.c\
	  file_open.c\
	  make_map.c\
	  mtoi.c\
	  find_square.c\
	  itom.c
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))
	
NAME = bsq

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $< $(INCS)
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	
re : fclean all
