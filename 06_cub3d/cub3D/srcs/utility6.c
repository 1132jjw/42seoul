/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:07:40 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 13:26:35 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (src1[i] == 0 || src2[i] == 0)
			return ((int)(src1[i] - src2[i]));
		if (src1[i] != src2[i])
			return ((int)(src1[i] - src2[i]));
		i++;
	}
	return (0);
}

int		min(int a, int b)
{
	return ((a < b) ? a : b);
}

int		max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		is_zero(double d)
{
	return (fabs(d) < 1e-06);
}

void	ft_error(t_game *game)
{
	if (game->map.r[0] <= 499 || game->map.r[0] >= 1901 ||\
	game->map.r[1] <= 499 || game->map.r[1] >= 1001)
		map_error();
}
