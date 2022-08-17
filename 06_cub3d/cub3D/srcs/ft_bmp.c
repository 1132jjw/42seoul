/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:58:19 by jeujeon           #+#    #+#             */
/*   Updated: 2021/05/19 12:48:02 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				write_bmp_header(t_game *game, int fd)
{
	unsigned char	bmp_h[54];
	int				file_size;

	ft_bzero(bmp_h, 54);
	file_size = 4 * game->map.r[1] * game->map.r[0] + 54;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = file_size;
	bmp_h[3] = (file_size >> 8);
	bmp_h[4] = (file_size >> 16);
	bmp_h[5] = (file_size >> 24);
	bmp_h[10] = 54;
	bmp_h[14] = 40;
	bmp_h[18] = game->map.r[0];
	bmp_h[19] = game->map.r[0] >> 8;
	bmp_h[20] = game->map.r[0] >> 16;
	bmp_h[21] = game->map.r[0] >> 24;
	bmp_h[22] = -game->map.r[1];
	bmp_h[23] = -game->map.r[1] >> 8;
	bmp_h[24] = -game->map.r[1] >> 16;
	bmp_h[25] = -game->map.r[1] >> 24;
	bmp_h[26] = 1;
	bmp_h[28] = 32;
	write(fd, bmp_h, 54);
}

void				ft_save(t_game *game)
{
	int				fd;

	fd = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0744);
	write_bmp_header(game, fd);
	write(fd, game->img.data, game->map.r[0] * game->map.r[1] * 4);
	close(fd);
	ft_exit("cub3D Event! cub.bmp file has been saved");
}
