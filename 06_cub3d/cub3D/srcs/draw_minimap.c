/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 15:32:35 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 20:16:55 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_lines(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.mx)
	{
		draw_line_v(game, i * MINIMAP_TILE_SIZE, 0,\
		MINIMAP_TILE_SIZE * game->map.my);
		i++;
	}
	draw_line_v(game, i * MINIMAP_TILE_SIZE - 1, 0,\
	MINIMAP_TILE_SIZE * game->map.my);
	i = 0;
	while (i < game->map.my)
	{
		draw_line_h(game, 0, MINIMAP_TILE_SIZE * game->map.mx,\
		i * MINIMAP_TILE_SIZE);
		i++;
	}
	draw_line_h(game, 0, MINIMAP_TILE_SIZE * game->map.mx,\
	i * MINIMAP_TILE_SIZE - 1);
}

void	draw_rectangle(t_game *game, int x, int y, unsigned int color)
{
	int i;
	int j;

	x *= MINIMAP_TILE_SIZE;
	y *= MINIMAP_TILE_SIZE;
	i = 0;
	while (i < MINIMAP_TILE_SIZE)
	{
		j = 0;
		while (j < MINIMAP_TILE_SIZE)
		{
			game->img.data[(y + i) * game->map.r[0] + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.my)
	{
		j = 0;
		while (j < game->map.mx)
		{
			if (game->map.map[i][j] == 1)
				draw_rectangle(game, j, game->map.my - i - 1, 0x000000);
			else if (game->map.map[i][j] == 2)
				draw_rectangle(game, j, game->map.my - i - 1, 0xFF0000);
			else
				draw_rectangle(game, j, game->map.my - i - 1, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			game->img.data[to_coord(game, game->param.x * TILE_SIZE / 10 + i,\
			(game->map.my - game->param.y) * TILE_SIZE / 10 + j)] = 0x00FF00;
			j++;
		}
		i++;
	}
}
