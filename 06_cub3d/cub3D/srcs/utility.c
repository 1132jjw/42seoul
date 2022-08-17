/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:33:54 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 01:13:55 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		deg_to_rad(double deg)
{
	double		rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

double		pixel_per_angle(t_game *game)
{
	return ((game->map.r[0] - 1) / game->fov_h);
}

double		angle_per_pixel(t_game *game)
{
	return (game->fov_h / (game->map.r[0] - 1));
}

int			to_coord(t_game *game, double x, double y)
{
	return ((int)floor(y) * game->map.r[0] + (int)floor(x));
}

double		fov_v(t_game *game)
{
	return ((double)game->map.r[1] / (double)game->map.r[0] * game->fov_h);
}
