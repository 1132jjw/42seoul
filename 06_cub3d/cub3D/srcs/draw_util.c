/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:07:22 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 20:18:57 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color(int *c)
{
	return (c[0] * 256 * 256 + c[1] * 256 + c[2]);
}

void	draw_line_v(t_game *game, double x, double y1, double y2)
{
	double	delta_x;
	double	delta_y;
	double	step;

	delta_x = 0;
	delta_y = y2 - y1;
	step = delta_y;
	delta_x /= step;
	delta_y /= step;
	while (is_zero(y2 - y1) == 0)
	{
		game->img.data[game->map.r[0] * (int)y1 + (int)x] = 0xb3b3b3;
		y1 += delta_y;
	}
}

void	draw_line_h(t_game *game, double x1, double x2, double y)
{
	double	delta_x;
	double	delta_y;
	double	step;

	delta_x = x2 - x1;
	delta_y = 0;
	step = delta_x;
	delta_x /= step;
	delta_y /= step;
	while (is_zero(x2 - x1) == 0)
	{
		game->img.data[game->map.r[0] * (int)y + (int)x1] = 0xb3b3b3;
		x1 += delta_x;
	}
}
