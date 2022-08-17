/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:14:11 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/16 19:55:14 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		range;
	int		*arr;
	int		i;

	if (max <= min)
		return (0);
	i = 0;
	range = max - min + 1;
	if (!(arr = malloc(sizeof(int) * (range + 1))))
		return (0);
	while (i < range - 1)
	{
		arr[i] = min + i;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
