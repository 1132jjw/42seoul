/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:43:50 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/17 22:46:01 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char				*ft_substr(char *s, int begin, int end)
{
	char		*ptr;
	int			len;
	int			i;

	len = end - begin;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[begin + i])
	{
		ptr[i] = s[begin + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int					except_space(t_game *game, int idx)
{
	int				jdx;

	jdx = 0;
	while (is_space(game->map.buf[idx][jdx]))
		jdx++;
	if (!game->map.buf[idx][jdx])
	{
		ft_free((void *)&game->map.buf[idx]);
		return (-1);
	}
	return (jdx);
}

void				check_num(t_game *game)
{
	if (game->map.r[0] <= 0 || game->map.r[1] <= 0 || game->map.c[0] < 0 \
	|| game->map.c[1] < 0 || game->map.c[2] < 0 || game->map.f[0] < 0 \
	|| game->map.f[1] < 0 || game->map.f[2] < 0 || game->map.c[0] > 255 \
	|| game->map.c[1] > 255 || game->map.c[2] > 255 || game->map.f[0] > 255 \
	|| game->map.f[1] > 255 || game->map.f[2] > 255)
		map_error();
}

void				check_mapdata(t_game *game)
{
	int				j;

	j = 0;
	while (j < (int)ft_strlen(game->map.parsed_map))
	{
		if (game->map.parsed_map[j] != '0' && game->map.parsed_map[j] != '1' \
		&& game->map.parsed_map[j] != '2' && game->map.parsed_map[j] != ' ' \
		&& game->map.parsed_map[j] != 'E' && game->map.parsed_map[j] != 'N' \
		&& game->map.parsed_map[j] != 'W' && game->map.parsed_map[j] != 'S' \
		&& game->map.parsed_map[j] != '\n')
			map_error();
		j++;
	}
}

void				ft_free(void **p)
{
	if (!p || !*p)
		return ;
	else
	{
		free(*p);
		*p = NULL;
	}
}
