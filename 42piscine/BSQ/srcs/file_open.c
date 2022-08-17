/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:08:23 by skim              #+#    #+#             */
/*   Updated: 2020/07/21 12:09:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		open_error(int fd)
{
	if (fd < 0)
	{
		write(1, "OPEN ERROR\n", 11);
		return (1);
	}
	return (0);
}

int		read_cnt_byte(int fd)
{
	char	buf[1];
	int		cnt;

	cnt = 0;
	while (read(fd, buf, 1) > 0)
	{
		buf[0] = '\0';
		++cnt;
	}
	close(fd);
	return (cnt);
}

int		read_data(int fd, char *buffer, int buf_size)
{
	int	len;

	if ((len = read(fd, buffer, buf_size)) > 0)
	{
		close(fd);
		return (len);
	}
	close(fd);
	return (0);
}

int		buf_from_file(char *argv, char **buf)
{
	int		fd;
	int		total_size;

	fd = open(argv, O_RDONLY);
	if (open_error(fd))
		return (0);
	total_size = read_cnt_byte(fd);
	if (!(*buf =  (char *)malloc(sizeof(char) * (total_size + 1))))
		return (0);
	(*buf)[total_size] = 0;
	fd = open(argv, O_RDONLY);
	if (read_data(fd, *buf, total_size))
	{
		return (1);
	}
	else
		return (0);
}
