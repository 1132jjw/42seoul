/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:58:00 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/18 18:44:37 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_elements(t_game *game, t_map *map_val, char *map, int y)
{
	int	i;

	if (map[0] != WALL || map[map_val->x - 1] != WALL)
		return (ERROR);
	i = -1;
	while (map[++i] != '\0')
	{
		if (map[i] == PLAYER)
		{
			map_val->player++;
			if (map_val->player > 1)
				return (ERROR);
			game->player->x = i;
			game->player->y = y;
		}
		else if (map[i] == COLLECTIBLE)
			map_val->collectible++;
		else if (map[i] == EXIT)
			map_val->exit++;
		else if (map[i] != ROAD && map[i] != WALL)
			return (ERROR);
	}
	return (0);
}

int	check_surrounded(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != WALL)
			return (ERROR);
		i++;
	}
	return (0);
}

int	to_coord(t_game *game, int x, int y)
{
	return (y * game->width + x);
}
