/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:32:35 by skim              #+#    #+#             */
/*   Updated: 2020/07/21 12:24:36 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdio.h>

int		ft_min(int a, int b, int c)
{
	a = a < b ? a : b;
	return (a < c ? a : c);
}

void	find_square(int **int_map, int size)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < g_row)
	{
		while (j < g_col)
		{
			if (int_map[i][j] == size)
			{
				int_map[i][j] = size;
				return ;
			}
			j++;
		}
		i++;
	}
}

int		find_size(int **int_map)
{
	int	i;
	int j;
	int size;

	i = g_row;
	j = g_col;
	size = 0;
	while (i > -1)
	{
		while (j > -1)
		{
			if (int_map[i][j] == 0)
				int_map[i][j] = 0;
			else 
			{
				int_map[i][j] = ft_min(int_map[i][j + 1], 
				int_map[i + 1][j], int_map[i + 1][j + 1]) + 1;
				size = size > int_map[i][j] ? size : int_map[i][j];
			}
			j--;
		}
		j = g_col;
		i--;
	}
	find_square(int_map, size);
	return (size);
}
