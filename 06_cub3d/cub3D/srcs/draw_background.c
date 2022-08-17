/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:06:59 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 20:13:56 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sky(t_game *game)
{
	int		i;
	int		j;

	j = 0;
	while (j < game->map.r[1] / 2)
	{
		i = 0;
		while (i < game->map.r[0])
		{
			game->img.data[j * game->map.r[0] + i] = color(game->map.c);
			i++;
		}
		j++;
	}
}

void	draw_floor(t_game *game)
{
	int		i;
	int		j;

	j = game->map.r[1] / 2;
	while (j < game->map.r[1])
	{
		i = 0;
		while (i < game->map.r[0])
		{
			game->img.data[j * game->map.r[0] + i] = color(game->map.f);
			i++;
		}
		j++;
	}
}
