/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:49:24 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/19 15:53:47 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	map_init(t_map *map)
{
	map->front = (t_node *)malloc(sizeof(t_node));
	map->rear = map->front;
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->player = 0;
	map->collectible = 0;
	map->enemy = 0;
	map->e_front = (t_enemy *)malloc(sizeof(t_enemy));
	map->e_rear = map->e_front;
	map->exit = 0;
	map->open = FALSE;
	return (0);
}

void	player_init(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->collectible = 0;
	player->movement = 0;
	player->happy_ending = FALSE;
	player->bad_ending = FALSE;
}

int	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->width = 1200;
	game->height = 800;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	game->imgs = (t_imgs *)malloc(sizeof(t_imgs));
	game->draw = (t_draw *)malloc(sizeof(t_draw));
	draw_init(game);
	game->fd = 0;
	game->finish = FALSE;
	game->error = FALSE;
	game->player = (t_player *)malloc(sizeof(t_player));
	player_init(game->player);
	game->map = (t_map *)malloc(sizeof(t_map));
	if (map_init(game->map) == ERROR)
		return (ERROR);
	return (0);
}
