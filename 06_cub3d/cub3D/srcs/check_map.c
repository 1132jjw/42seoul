/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:56:08 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 20:22:06 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				is_valid(t_game *game, int idx, int jdx)
{
	if (game->map.map[idx][jdx] == 0 || \
	(game->map.map[idx][jdx] >= 'A' && game->map.map[idx][jdx] <= 'Z') || \
	game->map.map[idx][jdx] == 2)
		map_error();
}

void				check_vertex(t_game *game, int idx, int jdx)
{
	if (idx == 0 && jdx == 0)
	{
		is_valid(game, idx, jdx + 1);
		is_valid(game, idx + 1, jdx);
		is_valid(game, idx + 1, jdx + 1);
	}
	else if (idx == 0 && jdx == game->map.mx - 1)
	{
		is_valid(game, idx, jdx - 1);
		is_valid(game, idx + 1, jdx);
		is_valid(game, idx + 1, jdx - 1);
	}
	else if (idx == game->map.my - 1 && jdx == 0)
	{
		is_valid(game, idx, jdx + 1);
		is_valid(game, idx - 1, jdx);
		is_valid(game, idx - 1, jdx + 1);
	}
	else if (idx == game->map.my - 1 && jdx == game->map.mx - 1)
	{
		is_valid(game, idx, jdx - 1);
		is_valid(game, idx - 1, jdx);
		is_valid(game, idx - 1, jdx - 1);
	}
}

void				check_row(t_game *game, int idx, int jdx)
{
	if (jdx == 0 && idx != 0 && idx != game->map.my - 1)
	{
		is_valid(game, idx - 1, jdx);
		is_valid(game, idx + 1, jdx);
		is_valid(game, idx - 1, jdx + 1);
		is_valid(game, idx, jdx + 1);
		is_valid(game, idx + 1, jdx + 1);
	}
	else if (jdx == game->map.mx - 1 && idx != 0 && idx != game->map.my - 1)
	{
		is_valid(game, idx - 1, jdx);
		is_valid(game, idx + 1, jdx);
		is_valid(game, idx - 1, jdx - 1);
		is_valid(game, idx, jdx - 1);
		is_valid(game, idx + 1, jdx - 1);
	}
}

void				check_col(t_game *game, int idx, int jdx)
{
	if (idx == 0 && jdx != 0 && jdx != game->map.mx - 1)
	{
		is_valid(game, idx, jdx - 1);
		is_valid(game, idx, jdx + 1);
		is_valid(game, idx + 1, jdx - 1);
		is_valid(game, idx + 1, jdx);
		is_valid(game, idx + 1, jdx + 1);
	}
	else if (idx == game->map.my - 1 && jdx != 0 && jdx != game->map.mx - 1)
	{
		is_valid(game, idx, jdx - 1);
		is_valid(game, idx, jdx + 1);
		is_valid(game, idx - 1, jdx - 1);
		is_valid(game, idx - 1, jdx);
		is_valid(game, idx - 1, jdx + 1);
	}
}

void				check_etc(t_game *game, int idx, int jdx)
{
	if (idx != 0 && jdx != 0 && \
		idx != game->map.my - 1 && jdx != game->map.mx - 1)
	{
		is_valid(game, idx - 1, jdx - 1);
		is_valid(game, idx - 1, jdx);
		is_valid(game, idx - 1, jdx + 1);
		is_valid(game, idx, jdx - 1);
		is_valid(game, idx, jdx + 1);
		is_valid(game, idx + 1, jdx - 1);
		is_valid(game, idx + 1, jdx);
		is_valid(game, idx + 1, jdx + 1);
	}
}
