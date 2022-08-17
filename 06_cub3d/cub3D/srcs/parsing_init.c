/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:04:10 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 21:05:39 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				get_route(t_game *game, int idx, int jdx)
{
	char			*ptr;
	int				s;
	int				end;

	end = jdx + 2;
	while (is_space(game->map.buf[idx][end]))
		end++;
	s = end;
	while (game->map.buf[idx][end] >= 33 && game->map.buf[idx][end] <= 126)
		end++;
	ptr = ft_substr(game->map.buf[idx], s, end);
	if (game->map.buf[idx][jdx] == 'E')
		game->map.ea = ft_strdup(ptr);
	else if (game->map.buf[idx][jdx] == 'N')
		game->map.no = ft_strdup(ptr);
	else if (game->map.buf[idx][jdx] == 'W')
		game->map.we = ft_strdup(ptr);
	else if (game->map.buf[idx][jdx] == 'S' && \
	game->map.buf[idx][jdx + 1] == 'O')
		game->map.so = ft_strdup(ptr);
	else if (game->map.buf[idx][jdx] == 'S' && \
	game->map.buf[idx][jdx + 1] != 'O')
		game->map.s = ft_strdup(ptr);
	free(ptr);
}

void				get_numdata(t_game *game, int idx, int jdx, int loop)
{
	int				x;
	int				start;
	int				end;

	x = -1;
	end = jdx + 1;
	while (++x < loop)
	{
		while (game->map.buf[idx][end] == ' ' || game->map.buf[idx][end] == ',')
			end++;
		start = end;
		while (game->map.buf[idx][end] >= '0' && \
				game->map.buf[idx][end] <= '9')
			end++;
		game->map.ptr = ft_substr(game->map.buf[idx], start, end);
		if (game->map.buf[idx][jdx] == 'R')
			game->map.r[x] = ft_atoi(game->map.ptr);
		else if (game->map.buf[idx][jdx] == 'C')
			game->map.c[x] = ft_atoi(game->map.ptr);
		else if (game->map.buf[idx][jdx] == 'F')
			game->map.f[x] = ft_atoi(game->map.ptr);
		free(game->map.ptr);
	}
}

void				get_data(t_game *game, int idx, int jdx)
{
	if (game->map.buf[idx][jdx] == 'R')
	{
		check_numdata(game, idx, jdx + 1, 2);
		get_numdata(game, idx, jdx, 2);
	}
	else if (game->map.buf[idx][jdx] == 'C' || game->map.buf[idx][jdx] == 'F')
	{
		check_numdata(game, idx, jdx + 1, 3);
		get_numdata(game, idx, jdx, 3);
	}
	else if (game->map.buf[idx][jdx] == 'E' || game->map.buf[idx][jdx] == 'N' \
	|| game->map.buf[idx][jdx] == 'W' || game->map.buf[idx][jdx] == 'S')
		get_route(game, idx, jdx);
	else
		map_error();
	free(game->map.buf[idx]);
}

void				read_map(t_game *game, int idx, int jdx)
{
	idx = 0;
	game->map.is_read = game->map.fd;
	while (game->map.is_read)
	{
		game->map.is_read = get_next_line(game->map.fd, &game->map.buf[idx]);
		jdx = except_space(game, idx);
		if (game->map.my > 0 && jdx == -1)
			map_error();
		if (jdx != -1 && game->map.buf[idx])
		{
			if (idx < 8)
			{
				get_data(game, idx, jdx);
				idx++;
			}
			else if (idx == 8)
			{
				ft_error(game);
				get_map(game, idx);
				game->map.my++;
			}
		}
	}
}

void				parsing_init(t_game *game, char *argv)
{
	int				idx;
	int				jdx;

	game->map.buf = (char **)malloc(sizeof(char *) * 10);
	game->map.fd = open(argv, O_RDONLY);
	if (game->map.fd == -1)
		ft_exit("game3D Error! No .game file");
	idx = 0;
	jdx = 0;
	game->map.r = (int *)malloc(sizeof(int) * 2);
	game->map.c = (int *)malloc(sizeof(int) * 3);
	game->map.f = (int *)malloc(sizeof(int) * 3);
	game->map.my = 0;
	read_map(game, idx, jdx);
	free(game->map.buf);
	close(game->map.fd);
	check_num(game);
	check_mapdata(game);
	map_init(game);
	check_map(game);
	free(game->map.parsed_map);
}
