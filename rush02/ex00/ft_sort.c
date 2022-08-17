/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:37:25 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/19 20:37:28 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_header.h"

void	swap(t_dict *now_arr, t_dict *next_arr)
{
	char *tmp;

	tmp = now_arr->key;
	now_arr->key = next_arr->key;
	next_arr->key = tmp;
	tmp = now_arr->value;
	now_arr->value = next_arr->value;
	next_arr->value = tmp;
}

int		ft_numcmp(char *s1, char *s2)
{
	unsigned int	idx;
	int				s1_len;
	int				s2_len;

	idx = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len != s2_len)
		return (s1_len - s2_len);
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

void	ft_sort(t_dict *dict_arr)
{
	int i;

	i = 0;
	while (i < (g_dict_len - 1))
	{
		if (ft_numcmp((dict_arr + i)->key, (dict_arr + i + 1)->key) > 0)
		{
			swap(&dict_arr[i], &dict_arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
