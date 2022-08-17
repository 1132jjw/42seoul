/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:18:52 by skim              #+#    #+#             */
/*   Updated: 2020/07/21 12:14:30 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>

int		count_row(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		count_col(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return (i);
}

void	ft_split(char *buf, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*buf != '\0')
	{
		while (*buf != '\n')
		{
			map[i][j] = *buf;
			j++;
			buf++;
		}
		map[i][j] = '\0';
		buf++;
		j = 0;
		i++;
	}
}

void	make_info(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n')
	{
		i++;
	}
	g_info[0] = buf[i - 1];
	g_info[1] = buf[i - 2];
	g_info[2] = buf[i - 3];
}

int		make_map(char *buf, char ***map)
{
	int	i;

	make_info(buf);
	g_row = count_row(buf) - 1;
	while (*buf != '\n')
		buf++;
	buf++;
	g_col = count_col(buf);
	if (!(*map = (char **)malloc(sizeof(char *) * (g_row + 1))))
		return (0);
	i = 0;
	while (i < g_row)
	{
		if (!((*map)[i] = (char *)malloc(sizeof(char) * (g_col + 1))))
			return (0);
		i++;
	}
	ft_split(buf, *map);
	return (1);
}
