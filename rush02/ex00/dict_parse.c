/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:44:02 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/19 17:26:35 by mcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_header.h"

void	put_value(char *value_nb, t_dict *save)
{
	int		i;
	char	*value_str;

	i = 0;
	while (value_nb[i] != '\0')
	{
		if (!(value_nb[i] >= 32 && value_nb[i] <= 126))
		{
			g_error = 1;
			return ;
		}
		i++;
	}
	value_str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (value_nb[i] != '\0')
	{
		value_str[i] = value_nb[i];
		i++;
	}
	value_str[i] = '\0';
	save->value = value_str;
}

void	put_key(char *nb, t_dict *save)
{
	int		i;
	char	*key_str;

	i = 0;
	while (nb[i] != '\0')
	{
		if (!(nb[i] >= '0' && nb[i] <= '9'))
		{
			g_error = 1;
			return ;
		}
		i++;
	}
	key_str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (nb[i] != '\0')
	{
		key_str[i] = nb[i];
		i++;
	}
	key_str[i] = '\0';
	save->key = key_str;
}

void	put_key_value(t_dict *dict, char *line)
{
	char	**splitted;
	char	*joined;
	int		cnt;
	int		line_size;

	line_size = 0;
	cnt = 0;
	splitted = ft_split(line, " ");
	while (line[line_size])
		line_size++;
	if (splitted[1] == 0)
		g_error = 1;
	if (g_flag == 0)
		g_error = 1;
	put_key(splitted[0], &dict[g_dict_len]);
	joined = ft_strjoin(ft_return_size(splitted + 1), splitted + 1, " ");
	put_value(joined, &dict[g_dict_len]);
	free(joined);
	g_dict_len++;
	while (splitted[cnt])
	{
		free(splitted[cnt]);
		cnt++;
	}
	free(splitted);
}

t_dict	*mk_dict(char *dict_file, int *idx)
{
	t_dict	*make_dict;
	int		fd;
	int		count;
	char	prev;

	prev = 0;
	count = 0;
	fd = open(dict_file, O_RDONLY);
	while ((*idx = read(fd, &g_char, 1)))
	{
		if (*idx == -1)
		{
			write(1, "Dict Error\n", 11);
			g_error = 1;
			return (0);
		}
		if (g_char == '\n' && prev != g_char)
			count++;
		prev = g_char;
	}
	close(fd);
	make_dict = (t_dict *)malloc(sizeof(t_dict) * (count));
	*idx = 0;
	return (make_dict);
}

t_dict	*parse(int fd, char *dict_file)
{
	t_dict	*dict;
	char	line[1000];
	int		idx;

	dict = mk_dict(dict_file, &idx);
	while (read(fd, &g_char, 1) && g_error == 0)
	{
		if (g_char == ':' && !g_flag)
		{
			g_char = ' ';
			g_flag = 1;
		}
		if (g_char == '\n')
		{
			if (idx != 0)
				line[idx] = '\0';
			if (idx != 0)
				put_key_value(dict, line);
			idx = 0;
			g_flag = 0;
			continue;
		}
		line[idx++] = g_char;
	}
	return (dict);
}
