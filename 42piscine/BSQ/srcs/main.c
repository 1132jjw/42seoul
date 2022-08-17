/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:15:46 by skim              #+#    #+#             */
/*   Updated: 2020/07/21 12:10:43 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_open.h"
#include "find_square.h"
#include "itom.h"
#include "make_map.h"
#include "mtoi.h"
#include "share.h"
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char 	*buf;
	char	**map;
	int		**int_map;
	int		size;
	int		i;

	i = 1;
	buf = 0;
	map = 0;
	int_map = 0;
	(void) argc;
	//while (i < argc)
	//{
		if (!(buf_from_file(argv[i], &buf)))
			return (0);
		if (!(make_map(buf, &map)))
			return (0);
		/*for (int i = 0; i < g_row; i++)
		{
			for (int j = 0; j < g_col; j++)
			{
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}
		*/
		if (!(mtoi(map, &int_map)))
			return (0);
		size = find_size(int_map);
		for (int i = 0; i < g_row + 1; i++)
		{
			for (int j = 0; j < g_col + 1; j++)
			{
				printf("%d ", int_map[i][j]);
			}
			printf("\n");
		}
		
		//printf("%d \n\n", size);
		itom(int_map, map, size);
		for (int i = 0; i < g_row; i++)
		{
			for (int j = 0; j < g_col; j++)
			{
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}
		free(buf);
		free(map);
		free(int_map);
		i++;
	//}
	return (0);
}
