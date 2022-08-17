
TARGET	= rush-02
SRCS	= main.c ft_str.c ft_split.c ft_translate.c ft_sort.c dict_parse.c ft_strjoin.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE = rush02_header.h

all: $(TARGET)

%.o: %.c ${INCLUDE}
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDE)

${TARGET}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(TARGET)

re: fclean all
