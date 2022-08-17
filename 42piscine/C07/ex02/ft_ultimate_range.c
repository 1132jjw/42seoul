/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:16:24 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/16 19:57:25 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		range_size;
	int		i;

	i = 0;
	range_size = max - min;
	if (range_size <= 0)
	{
		*range = 0;
		return (0);
	}
	if (!(*range = malloc(sizeof(int) * (range_size + 1))))
		return (-1);
	while (i < range_size)
	{
		(*range)[i] = min + i;
		i++;
	}
	(*range)[i] = '\0';
	return (range_size);
}
