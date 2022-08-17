/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:43:52 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/18 23:48:58 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*ft_strjoined(char *s1, char *s2)
{
	char		*ptr;
	int			i;
	int			j;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

int				sgn(double d)
{
	int		ret;

	ret = 2;
	if (is_zero(d))
		ret = 0;
	else if (d > 0)
		ret = 1;
	else if (d < 0)
		ret = -1;
	return (ret);
}

double			l2dist(double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;

	dx = x1 - x0;
	dy = y1 - y0;
	return (sqrt(dx * dx + dy * dy));
}

void			ft_swap(t_sprite *sprite, int i, int j)
{
	t_sprite	buf;

	buf = sprite[i];
	sprite[i] = sprite[j];
	sprite[j] = buf;
}

void			ft_qsort(t_sprite *sprite, int start, int end)
{
	int			pivot;
	int			i;
	int			j;

	if (start < end)
	{
		pivot = start;
		i = start + 1;
		j = end;
		while (i <= j)
		{
			while (i <= end && sprite[i].dist >= sprite[pivot].dist)
				i++;
			while (j > start && sprite[j].dist <= sprite[pivot].dist)
				j--;
			if (i > j)
				break ;
			ft_swap(sprite, i, j);
		}
		ft_swap(sprite, j, pivot);
		ft_qsort(sprite, start, j - 1);
		ft_qsort(sprite, j + 1, end);
	}
}
