/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 02:54:04 by mcho              #+#    #+#             */
/*   Updated: 2020/07/19 21:06:09 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_header.h"

char	*ft_pow(int n, char pow_1000[])
{
	int		idx;

	idx = 0;
	pow_1000[idx++] = '1';
	while (idx <= 3 * n)
	{
		pow_1000[idx++] = '0';
	}
	pow_1000[idx] = '\0';
	return (pow_1000);
}

int		useful(char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str[i])
		if (str[i++] != '0')
			res = 1;
	return (res);
}

int		find_dict(char *str, t_dict *dict_array)
{
	int		idx;
	int		cnt;
	int		check;

	cnt = 0;
	idx = 0;
	check = 0;
	while (idx < g_dict_len)
	{
		if (ft_strcmp(dict_array[idx].key, str) == 0)
		{
			check = 1;
			ft_strcat(g_answer, dict_array[idx].value);
			g_answer[ft_strlen(g_answer)] = ' ';
		}
		idx++;
	}
	if (check == 1)
		return (1);
	return (-1);
}

void	ft_translate(char *str, int cnt, char pow_1000[], t_dict *dict_array)
{
	char	temp[4];
	char	first_num[2];

	ft_strncpy(temp, str, ft_strlen(str));
	while (1)
	{
		if (ft_strlen(str) == 3)
		{
			if (useful(str) == 0)
				return ;
			if (temp[0] != '0')
				find_dict(ft_strncpy(first_num, temp, 1), dict_array);
			if (temp[0] != '0')
				find_dict("100", dict_array);
			ft_strncpy(temp, &str[1], 2);
		}
		if (find_dict(temp, dict_array) == 1)
			break ;
		find_dict(ft_strcat(ft_strncpy(first_num, temp, 1), "0"), dict_array);
		find_dict(ft_strncpy(first_num, &temp[1], 1), dict_array);
		break ;
	}
	if (cnt > 0)
		if (find_dict(ft_pow(cnt, pow_1000), dict_array) == -1)
			g_error = 1;
}

void	ft_read_argument(char *str, char pow_1000[], t_dict *dict_array)
{
	int		idx;
	char	temp[4];
	int		size;
	int		cnt;

	idx = 0;
	cnt = (ft_strlen(str) - 1) / 3;
	size = ft_strlen(str) % 3;
	if (size == 0)
		size = 3;
	while (str[idx])
	{
		ft_strncpy(temp, &str[idx], size);
		ft_translate(temp, cnt, pow_1000, dict_array);
		idx += size;
		size = 3;
		cnt--;
	}
}
