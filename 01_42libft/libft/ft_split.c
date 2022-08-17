/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:52:15 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:09:36 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_split_component(char const *s, int len, int i)
{
	char	*com;
	int		j;

	j = 0;
	com = malloc(sizeof(char) * (len + 1));
	while (j < len && s[i + j])
	{
		com[j] = s[i + j];
		j++;
	}
	com[j] = 0;
	return (com);
}

char	**make_split_memory(char const *s, int cnt, char c)
{
	char	**dou_pointer;
	int		nb;
	int		i;
	int		len;

	i = 0;
	nb = 0;
	dou_pointer = malloc(sizeof(char *) * (cnt + 1));
	while (s[i])
	{
		len = 0;
		if (s[i] && s[i] == c)
			i++;
		if (s[i + len] && s[i + len] != c)
		{
			while (s[i + len] && s[i + len] != c)
				len++;
			dou_pointer[nb] = make_split_component(s, len, i);
			i += len;
			nb++;
		}
	}
	dou_pointer[nb] = 0;
	return (dou_pointer);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		i;
	int		cnt;
	int		flag;

	flag = 0;
	i = 0;
	cnt = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (flag && s[i] == c)
		{
			cnt++;
			flag = 0;
		}
		else if (s[i] != c)
			flag = 1;
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		cnt++;
	splited = make_split_memory(s, cnt, c);
	return (splited);
}
