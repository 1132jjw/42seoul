CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = cub3D
SRCS_DIR = ./srcs
SRCS_NAME = main.c draw_wall.c init.c utility.c draw_minimap.c\
			get_next_line.c get_next_line_utils.c map_parsing.c\
			parsing_init.c utility2.c check_map.c ft_atoi.c\
			ft_bmp.c utility3.c utility4.c utility5.c\
			draw_util.c draw_sprite.c ft_get_wall.c ft_key.c\
			draw_background.c ft_dda.c utility6.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)
FRW = -framework

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -lmlx -L../mlx $(FRW) OpenGL $(FRW) AppKit -o $(NAME)
	rm -f $(OBJS)

clean :
	rm -f $(OBJS)
	rm -f a.out
	rm -f cub3D
	rm -f cub3D.bmp

fclean : clean
	rm -f $(NAME)

re : fclean all

