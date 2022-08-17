/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:20:20 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 11:30:47 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_visible(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->visible = malloc(sizeof(int *) * game->map.my + 1);
	while (i < game->map.my)
	{
		game->visible[i] = malloc(sizeof(int) * game->map.mx + 1);
		i++;
	}
	i = 0;
	while (i < game->map.my)
	{
		j = 0;
		while (j < game->map.mx)
		{
			game->visible[i][j] = 0;
			j++;
		}
		i++;
	}
}

void			free_visible_zbuf(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.my)
	{
		free(game->visible[i]);
		i++;
	}
	free(game->visible);
	game->visible = 0;
	free(game->zbuf);
	game->zbuf = 0;
}

t_sprite		*ft_realloc(t_game *game, int size)
{
	int			i;
	t_sprite	*ret;

	ret = (t_sprite *)malloc(sizeof(t_sprite) * size);
	i = 0;
	while (i < game->sprite.n)
	{
		ret[i] = game->sp[i];
		i++;
	}
	free(game->sp);
	return (ret);
}

void			get_sprite_data(t_game *game, int x, int y)
{
	if (game->sprite.n == 0)
		game->sp = (t_sprite *)malloc(sizeof(t_sprite));
	else
		game->sp = ft_realloc(game, game->sprite.n + 1);
	game->sp[game->sprite.n].tex = (map_get_cell(game, x, y) - 1) + 5;
	game->sp[game->sprite.n].x = x;
	game->sp[game->sprite.n].y = y;
	game->sp[game->sprite.n].th = atan2((y + 0.5) -\
	(game->param.y), (x + 0.5) - (game->param.x));
	if (game->sp[game->sprite.n].th < 0)
		game->sp[game->sprite.n].th += M_PI * 2;
	game->sp[game->sprite.n].dist = l2dist(game->param.x, game->param.y,\
	x + 0.5, y + 0.5) * cos(game->param.angle - game->sp[game->sprite.n].th);
	game->sprite.n++;
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	big_len;
	size_t	little_len;

	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = 0;
	j = 0;
	if (big_len < little_len)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && i < big_len)
	{
		while (big[i + j] == little[j] && j < little_len)
			j++;
		if (j == little_len && (i + j) <= len)
			return ((char *)&big[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
