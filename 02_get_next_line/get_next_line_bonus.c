/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:39:46 by jeujeon           #+#    #+#             */
/*   Updated: 2020/11/05 12:43:02 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ret_tmp(char *tmp, char **line)
{
	char	*res;
	int		i;
	int		idx;

	i = 0;
	idx = -1;
	while (tmp[i] != '\n' && tmp[i] != 0)
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	while (++idx < i)
		res[idx] = tmp[idx];
	res[idx] = 0;
	*line = ft_strjoin(*line, res);
	free(res);
	if (tmp[i] == 0)
		ft_bzero(tmp, BUFFER_SIZE + 1);
	if (tmp[i++] == 0)
		return (0);
	idx = 0;
	while (i < BUFFER_SIZE)
		tmp[idx++] = tmp[i++];
	while (idx <= BUFFER_SIZE)
		tmp[idx++] = 0;
	return (1);
}

int		ft_checknl_cpytmp(char *buff, int idx, char *tmp, char **line)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	while (i < idx)
	{
		if (buff[i] == '\n')
			flag = 1;
		if (buff[i] == 0)
			flag = 1;
		i++;
	}
	if (flag)
	{
		ft_strcpy(tmp, buff);
		ret_tmp(tmp, line);
	}
	return (flag);
}

void	type_idx(char *tmp, int idx, int flag, char **line)
{
	if (idx < 0)
		ft_bzero(tmp, BUFFER_SIZE);
	if (idx == 0 && flag == 0)
	{
		ft_bzero(tmp, BUFFER_SIZE);
		*line = ft_strdup("");
	}
}

int		if_remain_tmp(char *tmp, char **line, int *flag, char *buff)
{
	if (tmp[0] != '\0')
	{
		*line = 0;
		*flag = 1;
		if (ret_tmp(tmp, line))
		{
			free(buff);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		tmp[OPEN_MAX][BUFFER_SIZE + 1];
	int				idx;
	int				flag;

	flag = 0;
	if (line == 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (if_remain_tmp(tmp[fd], line, &flag, buff))
		return (1);
	while ((idx = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (flag != 1)
			*line = 0;
		flag = 1;
		buff[idx] = '\0';
		if (ft_checknl_cpytmp(buff, idx, tmp[fd], line))
			break ;
		*line = ft_strjoin(*line, buff);
	}
	free(buff);
	type_idx(tmp[fd], idx, flag, line);
	return (idx);
}
