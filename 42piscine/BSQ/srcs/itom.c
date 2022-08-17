/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:57:20 by skim              #+#    #+#             */
/*   Updated: 2020/07/21 12:10:18 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <unistd.h>

void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_row)
	{
		while (j < g_col)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void	draw_square(char **map, int i, int j, int size)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < size)
	{
		while (b < size)
		{
			map[i + a][j + b] = g_info[0];
			b++;
		}
		b = 0;
		a++;
	}
}

void	itom(int **int_map, char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_row)
	{
		while (j < g_col)
		{
			if (int_map[i][j] == size)
			{
				draw_square(map, i, j, size);
				return ;
			}	
			j++;
		}
		j = 0;
		i++;
	}
	print_map(map);
}
