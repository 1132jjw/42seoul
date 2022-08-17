/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:19:23 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 13:21:14 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				get_visible_sprite(t_game *game)
{
	int			x;
	int			y;

	game->sp = NULL;
	x = 0;
	game->sprite.n = 0;
	while (x < game->map.mx)
	{
		y = 0;
		while (y < game->map.my)
		{
			if (game->visible[y][x] == 0 || map_get_cell(game, x, y) <= 1 ||\
			map_get_cell(game, x, y) >= 'A')
			{
				y++;
				continue;
			}
			get_sprite_data(game, x, y);
			y++;
		}
		x++;
	}
	game->sprite.nsp = game->sprite.n;
}

void				get_sprites_height(t_game *game, int x)
{
	int		y;

	game->sprite.txratio = (double)(x - game->sprite.cx) \
	/ game->sprite.sh + 0.5;
	game->sprite.tx = (int)(game->sprite.txratio * game->ptex->img_width);
	game->sprite.y0 = (int)((game->map.r[1] - game->sprite.sh) / 2.0);
	y = max(0, game->sprite.y0);
	while (y < min(game->map.r[1], game->sprite.y0 + game->sprite.sh))
	{
		game->sprite.ty = (int)((double)(y - game->sprite.y0) \
		* game->ptex->img_height / game->sprite.sh);
		game->sprite.color = game->ptex->data[game->sprite.ty \
		* game->ptex->img_width + game->sprite.tx];
		if ((game->sprite.color & 0x00ffffff) == 0)
		{
			y++;
			continue ;
		}
		game->img.data[y * game->map.r[0] + x] = game->sprite.color;
		y++;
	}
}

void				get_sprites_width(t_game *game, int i)
{
	game->sprite.sh = get_wall_height(game, game->sp[i].dist);
	game->ptex = &(game->sp_img);
	game->sprite.angle = game->sp[i].th - game->param.angle;
	if (game->sprite.angle > M_PI)
		game->sprite.angle -= M_PI * 2;
	else if (game->sprite.angle < -M_PI)
		game->sprite.angle += M_PI * 2;
	game->sprite.cx = (int)((game->fov_h_2 - game->sprite.angle) *\
	pixel_per_angle(game));
	game->sprite.xmin = max(0, game->sprite.cx - game->sprite.sh / 2);
	game->sprite.xmax = min(game->map.r[0], game->sprite.cx +\
	game->sprite.sh / 2);
}

void				sprite_check(t_game *game, int i)
{
	int		x;

	x = game->sprite.xmin;
	while (x < game->sprite.xmax)
	{
		if (game->sp[i].dist > game->zbuf[x])
		{
			x++;
			continue ;
		}
		if (game->sp[i].dist <= 0.5)
		{
			x++;
			continue ;
		}
		get_sprites_height(game, x);
		x++;
	}
}

void				draw_sprites(t_game *game)
{
	int			i;

	game->sprite.nsp = 0;
	get_visible_sprite(game);
	ft_qsort(game->sp, 0, game->sprite.nsp - 1);
	i = 0;
	while (i < game->sprite.nsp)
	{
		get_sprites_width(game, i);
		sprite_check(game, i);
		i++;
	}
	if (game->sprite.nsp > 0)
		free(game->sp);
}
