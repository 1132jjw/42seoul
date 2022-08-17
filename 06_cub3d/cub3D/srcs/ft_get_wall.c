/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:12:09 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 01:14:40 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_get_cell(t_game *game, int x, int y)
{
	return ((x >= 0 && x < game->map.mx && y >= 0 && \
	y < game->map.my) ? game->map.map[y][x] : -1);
}

double	get_dist(t_game *game, int x)
{
	double	ray;
	double	dist;

	ray = (game->param.angle + game->fov_h_2) - (x * angle_per_pixel(game));
	if (get_wall_intersection(game, ray) == 0)
		return (INFINITY);
	dist = l2dist(game->param.x, game->param.y, \
	game->param.sight_x, game->param.sight_y);
	dist *= cos(game->param.angle - ray);
	return (dist);
}

int		get_wall_height(t_game *game, double dist)
{
	double	fov_h;
	int		res;

	fov_h = 2.0 * dist * tan(fov_v(game) / 2.0);
	res = (int)(game->map.r[1] * (WALL_H / fov_h));
	return (res);
}
