/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:30:25 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 21:05:06 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				check_map(t_game *game)
{
	int				idx;
	int				jdx;

	idx = -1;
	game->map.is_overlap = 0;
	while (++idx < game->map.my)
	{
		jdx = -1;
		while (++jdx < game->map.mx)
		{
			if (game->map.map[idx][jdx] == 8)
			{
				check_vertex(game, idx, jdx);
				check_row(game, idx, jdx);
				check_col(game, idx, jdx);
				check_etc(game, idx, jdx);
			}
			if (game->map.map[idx][jdx] > 'A' && game->map.map[idx][jdx] < 'Z')
			{
				if (game->map.is_overlap == 1)
					ft_exit("game3D Error! One more player in map");
				game->map.is_overlap = 1;
			}
		}
	}
}

void				fill_space(t_game *game, int idx, int jdx)
{
	while (jdx < game->map.mx)
	{
		game->map.map[idx][jdx] = 8;
		jdx++;
	}
}

void				fill_map(t_game *game)
{
	if (game->map.parsed_map[game->map.kdx] == '\n' && \
		game->map.jdx != 0 && game->map.kdx \
		< (int)ft_strlen(game->map.parsed_map))
	{
		while (game->map.jdx < game->map.mx)
			game->map.map[game->map.my - 1 - game->map.idx]\
			[game->map.jdx++] = 8;
	}
	else if (game->map.parsed_map[game->map.kdx] == '0' || \
			game->map.parsed_map[game->map.kdx] == '1' || \
			game->map.parsed_map[game->map.kdx] == '2')
		game->map.map[game->map.my - 1 - game->map.idx][game->map.jdx] = \
		game->map.parsed_map[game->map.kdx] - '0';
	else if (is_player(game->map.parsed_map[game->map.kdx]))
		game->map.map[game->map.my - 1 - game->map.idx][game->map.jdx] = \
		game->map.parsed_map[game->map.kdx];
	else if (is_space(game->map.parsed_map[game->map.kdx]))
		game->map.map[game->map.my - 1 - game->map.idx][game->map.jdx] = 8;
	else
		map_error();
}

void				map_init(t_game *game)
{
	game->map.my += 2;
	game->map.map = (int **)malloc(sizeof(int *) * game->map.my);
	game->map.idx = 0;
	game->map.kdx = 0;
	while (game->map.idx < game->map.my)
	{
		game->map.map[game->map.my - 1 - game->map.idx] = \
		(int *)malloc(sizeof(int) * (game->map.mx));
		game->map.jdx = 0;
		if (game->map.idx == 0 || game->map.idx == game->map.my - 1)
			fill_space(game, game->map.my - 1 - game->map.idx, game->map.jdx);
		else
		{
			while (game->map.jdx < game->map.mx)
			{
				fill_map(game);
				game->map.jdx++;
				game->map.kdx++;
			}
		}
		game->map.idx++;
	}
}

void				get_map(t_game *game, int idx)
{
	char			*room;

	room = ft_strjoined(" ", game->map.buf[idx]);
	free(game->map.buf[idx]);
	game->map.buf[idx] = ft_strdup(room);
	free(room);
	room = ft_strjoined(game->map.buf[idx], "\n");
	free(game->map.buf[idx]);
	game->map.buf[idx] = ft_strdup(room);
	free(room);
	if (game->map.my == 0)
	{
		game->map.mx = ft_strlen(game->map.buf[idx]);
		game->map.parsed_map = ft_strdup(game->map.buf[idx]);
	}
	else
	{
		if (game->map.mx < (int)ft_strlen(game->map.buf[idx]))
			game->map.mx = ft_strlen(game->map.buf[idx]);
		room = ft_strjoined(game->map.parsed_map, game->map.buf[idx]);
		free(game->map.parsed_map);
		game->map.parsed_map = ft_strdup(room);
		free(room);
	}
	free(game->map.buf[idx]);
}
