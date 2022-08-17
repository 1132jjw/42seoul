/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:11:54 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 13:09:18 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_game *game, double dist, int x)
{
	int		y;

	game->ray.wh = get_wall_height(game, dist);
	game->ray.y0 = (int)((game->map.r[1] - game->ray.wh) / 2.0);
	game->ray.y1 = game->ray.y0 + game->ray.wh - 1;
	game->ray.ystart = max(0, game->ray.y0);
	y = game->ray.ystart;
	game->ray.yend = min(game->map.r[1] - 1, game->ray.y1);
	game->ray.txratio = (game->wall_type == W || game->wall_type == E) \
	? (game->param.sight_y - floor(game->param.sight_y)) \
	: (game->param.sight_x - floor(game->param.sight_x));
	while (y <= game->ray.yend)
	{
		get_texture_color_we(game, y);
		get_texture_color_sn(game, y);
		game->img.data[y * game->map.r[0] + x] = game->ray.color;
		y++;
	}
}

void	get_texture_color_we(t_game *game, int y)
{
	if (game->wall_type == W)
	{
		game->ray.tx = (int)(game->ray.txratio * game->w_img.img_height);
		game->ray.ty = (int)((double)(y - game->ray.y0) * \
		game->w_img.img_height / game->ray.wh);
		game->ray.color = game->w_img.data[game->ray.ty * \
		game->w_img.img_width + game->ray.tx];
	}
	else if (game->wall_type == E)
	{
		game->ray.tx = (int)(game->ray.txratio * game->e_img.img_height);
		game->ray.ty = (int)((double)(y - game->ray.y0) * \
		game->e_img.img_height / game->ray.wh);
		game->ray.color = game->e_img.data[game->ray.ty * \
		game->e_img.img_width + game->ray.tx];
	}
}

void	get_texture_color_sn(t_game *game, int y)
{
	if (game->wall_type == S)
	{
		game->ray.tx = (int)(game->ray.txratio * game->s_img.img_height);
		game->ray.ty = (int)((double)(y - game->ray.y0) * \
		game->s_img.img_height / game->ray.wh);
		game->ray.color = game->s_img.data[game->ray.ty * \
		game->s_img.img_width + game->ray.tx];
	}
	else if (game->wall_type == N)
	{
		game->ray.tx = (int)(game->ray.txratio * game->n_img.img_height);
		game->ray.ty = (int)((double)(y - game->ray.y0) * \
		game->n_img.img_height / game->ray.wh);
		game->ray.color = game->n_img.data[game->ray.ty * \
		game->n_img.img_width + game->ray.tx];
	}
}
