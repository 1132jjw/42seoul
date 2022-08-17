/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:53:49 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/17 22:45:16 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int					is_player(char player)
{
	if (player == 'E' || player == 'N' || player == 'W' || player == 'S')
	{
		if (player == 'E')
			return ('E');
		else if (player == 'N')
			return ('N');
		else if (player == 'W')
			return ('W');
		else if (player == 'S')
			return ('S');
	}
	return (0);
}

void				map_error(void)
{
	ft_exit("Cub3D Error: Invalid map");
}

void				check_numdata(t_game *game, int idx, int jdx, int check)
{
	while (game->map.buf[idx][jdx])
	{
		if (!(game->map.buf[idx][jdx] == ' ' || game->map.buf[idx][jdx] == ',' \
		|| (game->map.buf[idx][jdx] >= '0' && game->map.buf[idx][jdx] <= '9')) \
		|| check == 0)
			map_error();
		while (game->map.buf[idx][jdx] == ' ' || game->map.buf[idx][jdx] == ',')
			jdx++;
		if (game->map.buf[idx][jdx] >= '0' && game->map.buf[idx][jdx] <= '9')
			check--;
		while (game->map.buf[idx][jdx] >= '0' && game->map.buf[idx][jdx] <= '9')
			jdx++;
	}
}

int					ft_exit(char *s)
{
	if (s)
		printf("%s\n", s);
	exit(0);
	return (0);
}
