/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:23:20 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 20:48:11 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_init(t_game *game, double ray)
{
	game->ray.xstep = sgn(cos(ray));
	game->ray.ystep = sgn(sin(ray));
	game->ray.xslope = (game->ray.xstep == 0) ? INFINITY : tan(ray);
	game->ray.yslope = (game->ray.ystep == 0) ? INFINITY : 1 / tan(ray);
	if (game->ray.xstep > 0)
		game->ray.nx = floor(game->param.x) + 1;
	else if (game->ray.xstep < 0)
		game->ray.nx = ceil(game->param.x) - 1;
	else
		game->ray.nx = game->param.x;
	if (game->ray.ystep > 0)
		game->ray.ny = floor(game->param.y) + 1;
	else if (game->ray.ystep < 0)
		game->ray.ny = ceil(game->param.y) - 1;
	else
		game->ray.ny = game->param.y;
	game->ray.f = INFINITY;
	game->ray.g = INFINITY;
	game->ray.hit = 0;
}

void	dda(t_game *game)
{
	if (game->ray.xstep != 0)
		game->ray.f = game->ray.xslope * (game->ray.nx - game->param.x) +\
		game->param.y;
	if (game->ray.ystep != 0)
		game->ray.g = game->ray.yslope * (game->ray.ny - game->param.y) +\
		game->param.x;
	game->ray.dist_v = l2dist(game->param.x, game->param.y, game->ray.nx,\
	game->ray.f);
	game->ray.dist_h = l2dist(game->param.x, game->param.y, game->ray.g,\
	game->ray.ny);
	if (game->ray.dist_v < game->ray.dist_h)
	{
		game->ray.mapx = (game->ray.xstep == 1) ? (int)(game->ray.nx) :\
		(int)(game->ray.nx) - 1;
		game->ray.mapy = (int)game->ray.f;
		game->ray.hit_side = 0;
	}
	else
	{
		game->ray.mapx = (int)game->ray.g;
		game->ray.mapy = (game->ray.ystep == 1) ? (int)(game->ray.ny) :\
		(int)(game->ray.ny) - 1;
		game->ray.hit_side = 1;
	}
}

void	get_wall_type(t_game *game)
{
	if (game->ray.hit_side == 0)
	{
		game->wall_type = (game->ray.xstep > 0) ? W : E;
		game->param.sight_x = game->ray.nx;
		game->param.sight_y = game->ray.f;
	}
	else
	{
		game->wall_type = (game->ray.ystep > 0) ? S : N;
		game->param.sight_x = game->ray.g;
		game->param.sight_y = game->ray.ny;
	}
	game->ray.hit = 1;
}

int		get_wall_intersection(t_game *game, double ray)
{
	dda_init(game, ray);
	while (!game->ray.hit)
	{
		dda(game);
		game->ray.cell = map_get_cell(game, game->ray.mapx, game->ray.mapy);
		if (game->ray.cell < 0)
			break ;
		if (game->ray.cell == 1)
		{
			get_wall_type(game);
			break ;
		}
		game->visible[game->ray.mapy][game->ray.mapx] = 1;
		if (game->ray.hit_side == 0)
			game->ray.nx += game->ray.xstep;
		else
			game->ray.ny += game->ray.ystep;
	}
	return (game->ray.hit);
}
