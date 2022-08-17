/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:29:50 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 01:15:55 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			get_player_data(t_game *game)
{
	if (game->map.map[(int)game->param.y][(int)game->param.x] == 'E')
		game->param.angle = deg_to_rad(0);
	else if (game->map.map[(int)game->param.y][(int)game->param.x] == 'N')
		game->param.angle = deg_to_rad(90);
	else if (game->map.map[(int)game->param.y][(int)game->param.x] == 'W')
		game->param.angle = deg_to_rad(180);
	else
		game->param.angle = deg_to_rad(270);
	game->fov_h = deg_to_rad(FOV);
	game->fov_h_2 = game->fov_h / 2;
}

void			player_init(t_game *game)
{
	game->param.y = 0;
	while (game->param.y < game->map.my)
	{
		game->param.x = 0;
		while (game->param.x < game->map.mx)
		{
			if (game->map.map[(int)game->param.y][(int)game->param.x] >= 'A')
			{
				get_player_data(game);
				game->param.x += 0.5;
				game->param.y += 0.5;
				game->param.sight_x = game->param.x;
				game->param.sight_y = game->param.y;
				return ;
			}
			game->param.x++;
		}
		game->param.y++;
	}
	ft_exit("Cub3D Error: doesn't exist player in map");
}

void			img_init(t_game *game)
{
	game->n_img.img = mlx_xpm_file_to_image(game->mlx, game->map.no, \
	&game->n_img.img_width, &game->n_img.img_height);
	game->s_img.img = mlx_xpm_file_to_image(game->mlx, game->map.so, \
	&game->s_img.img_width, &game->s_img.img_height);
	game->e_img.img = mlx_xpm_file_to_image(game->mlx, game->map.ea, \
	&game->e_img.img_width, &game->e_img.img_height);
	game->w_img.img = mlx_xpm_file_to_image(game->mlx, game->map.we, \
	&game->w_img.img_width, &game->w_img.img_height);
	game->sp_img.img = mlx_xpm_file_to_image(game->mlx, game->map.s, \
	&game->sp_img.img_width, &game->sp_img.img_height);
	game->img.img = mlx_new_image(game->mlx, game->map.r[0], game->map.r[1]);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, \
	&game->img.bpp, &game->img.size_l, &game->img.endian);
	game->n_img.data = (int *)mlx_get_data_addr(game->n_img.img, \
	&game->n_img.bpp, &game->n_img.size_l, &game->n_img.endian);
	game->s_img.data = (int *)mlx_get_data_addr(game->s_img.img, \
	&game->s_img.bpp, &game->s_img.size_l, &game->s_img.endian);
	game->e_img.data = (int *)mlx_get_data_addr(game->e_img.img, \
	&game->e_img.bpp, &game->e_img.size_l, &game->e_img.endian);
	game->w_img.data = (int *)mlx_get_data_addr(game->w_img.img, \
	&game->w_img.bpp, &game->w_img.size_l, &game->w_img.endian);
	game->sp_img.data = (int *)mlx_get_data_addr(game->sp_img.img, \
	&game->sp_img.bpp, &game->sp_img.size_l, &game->sp_img.endian);
}

void			win_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.r[0], game->map.r[1], "1");
}
