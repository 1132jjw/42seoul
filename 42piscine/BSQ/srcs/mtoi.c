/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:58:01 by skim              #+#    #+#             */
/*   Updated: 2020/07/21 12:23:31 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

void	change_map(int **int_map, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_row + 1)
	{
		while (j < g_col + 1)
		{
			if (i == g_row || j == g_col)
				int_map[i][j] = 0;
			else
			{
				if (map[i][j] == g_info[1])
					int_map[i][j] = 0;
				else if (map[i][j] == g_info[2])
					int_map[i][j] = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		mtoi(char **map, int ***int_map)
{
	int i;

	i = 0;
	if (!(*int_map = (int **)malloc(sizeof(int *) * (g_row + 2))))
		return (0);
	while (i < g_row + 2)
	{
		if (!((*int_map)[i] = (int *)malloc(sizeof(int) * (g_col + 2))))
			return (0);
		i++;
	}
	change_map(*int_map, map);
	return (1);
}
