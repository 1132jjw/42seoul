/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:06:39 by jeonjeung         #+#    #+#             */
/*   Updated: 2021/05/19 01:19:48 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_RIGHT		0x7C
# define KEY_LEFT		0x7B
# define TILE_SIZE 60
# define MINIMAP_TILE_SIZE 6
# define WALL_H 1.0
# define FOV 60
# define SP 4
# define N 3
# define S 2
# define E 1
# define W 0

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				img_width;
	int				img_height;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_param
{
	double			x;
	double			y;
	double			sight_x;
	double			sight_y;
	double			angle;
}					t_param;

typedef struct		s_sprite
{
	int				tex;
	int				x;
	int				y;
	double			dist;
	double			th;
	int				nsp;
	int				sh;
	double			angle;
	int				cx;
	int				xmin;
	int				xmax;
	double			txratio;
	int				tx;
	int				y0;
	int				ty;
	int				color;
	int				n;
}					t_sprite;

typedef struct		s_map
{
	int				fd;
	int				is_read;
	char			**buf;
	int				*r;
	char			*ea;
	char			*no;
	char			*we;
	char			*so;
	char			*s;
	int				*c;
	int				*f;
	int				mx;
	int				my;
	char			*parsed_map;
	int				**map;
	int				mapx;
	int				mapy;
	int				idx;
	int				jdx;
	int				kdx;
	int				is_overlap;
	char			*ptr;
}					t_map;

typedef struct		s_ray
{
	int				wh;
	int				y0;
	int				y1;
	int				ystart;
	int				yend;
	int				ty;
	int				color;
	double			txratio;
	int				tx;
	int				xstep;
	int				ystep;
	double			xslope;
	double			yslope;
	double			nx;
	double			ny;
	double			f;
	double			g;
	int				hit;
	int				hit_side;
	int				mapx;
	int				mapy;
	double			dist_v;
	double			dist_h;
	int				cell;
}					t_ray;

typedef struct		s_game
{
	void			*mlx;
	void			*win;
	double			fov_h;
	double			fov_h_2;
	int				save;
	t_ray			ray;
	t_sprite		sprite;
	t_sprite		*sp;
	t_img			*ptex;
	t_param			param;
	t_img			img;
	t_img			n_img;
	t_img			s_img;
	t_img			w_img;
	t_img			e_img;
	t_img			sp_img;
	t_map			map;
	double			*zbuf;
	int				wall_type;
	int				**visible;
}					t_game;

int					wall_detect(t_game *game, double sight_x, double sight_y);
void				player_init(t_game *game);
void				img_init(t_game *game);
void				win_init(t_game *game);
void				game_init(t_game *game);
int					key_press(int keycode, t_game *game);

int					color(int *c);
void				draw_lines(t_game *game);
void				draw_rectangle(t_game *game, int x,\
					int y, unsigned int color);
void				draw_rectangles(t_game *game);
void				draw_player(t_game *game);
void				draw_line_v(t_game *game, double x, double y1, double y2);
void				draw_line_h(t_game *game, double x1, double x2, double y);
void				draw_sky(t_game *game);
void				draw_floor(t_game *game);
void				draw_sprites(t_game *game);
void				put_pixel_to_img(t_game *game, double x,\
					double y, unsigned int color);
void				main_draw(t_game *game);
void				draw_minimap_player_sight(t_game *game);

void				parsing_init(t_game *game, char *argv);
void				check_vertex(t_game *game, int idx, int jdx);
void				check_row(t_game *game, int idx, int jdx);
void				check_col(t_game *game, int idx, int jdx);
void				check_etc(t_game *game, int idx, int jdx);
int					is_space(char c);
int					is_player(char player);
void				map_error(void);

int					ft_exit(char *s);
char				*ft_substr(char *s, int begin, int end);
int					ft_atoi(char *str);
void				check_numdata(t_game *game, int idx, int jdx, int check);
int					except_space(t_game *game, int idx);
void				check_num(t_game *game);
void				check_mapdata(t_game *game);
void				get_map(t_game *game, int idx);
void				map_init(t_game *game);
void				check_map(t_game *game);
void				ft_free(void **p);
char				*ft_strjoined(char *s1, char *s2);

double				deg_to_rad(double deg);
double				angle_per_pixel(t_game *game);
double				pixel_per_angle(t_game *game);
double				fov_v(t_game *game);

int					to_coord(t_game *game, double x, double y);
void				ft_save(t_game *game);
int					sgn(double d);
int					map_get_cell(t_game *game, int x, int y);
double				l2dist(double x0, double y0, double x1, double y1);
void				ft_qsort(t_sprite *sprite, int start, int end);
void				init_visible(t_game *game);
double				get_dist(t_game *game, int x);
int					get_wall_height(t_game *game, double dist);
int					get_wall_intersection(t_game *game, double ray);
void				get_texture_color_we(t_game *game, int y);
void				get_texture_color_sn(t_game *game, int y);
void				draw_wall(t_game *game, double dist, int x);
void				free_visible_zbuf(t_game *game);
void				ft_error(t_game *game);
void				get_sprite_data(t_game *game, int x, int y);
char				*ft_strnstr(const char *big,\
					const char *little, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					min(int a, int b);
int					max(int a, int b);
int					is_zero(double d);

#endif
