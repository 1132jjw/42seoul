/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 12:54:05 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/22 12:54:06 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_no;
int g_charset[256] = {0, };

char	**ft_mk_split(char *str)
{
	int		flag;
	char	**base;

	g_no = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (flag && g_charset[(int)*str] == 1)
		{
			g_no++;
			flag = 0;
		}
		else if (g_charset[(int)*str] == 0)
			flag = 1;
		str++;
	}
	if (g_charset[(int)*(str - 1)] == 0)
		g_no++;
	if (!(base = (char **)malloc(sizeof(char *) * (g_no + 1))))
		return (0);
	return (base);
}

char	*save_str(char **str, int size)
{
	int		i;
	int		flag;
	char	*save;

	i = 0;
	flag = 0;
	save = (char *)malloc(sizeof(char) * (size + 1));
	while (**str != '\0')
	{
		if (g_charset[(int)**str] == 0)
		{
			save[i++] = **str;
			flag = 1;
		}
		else if (g_charset[(int)**str] == 1 && flag == 1)
			break ;
		(*str)++;
	}
	save[i] = '\0';
	return (save);
}

int		return_size(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (g_charset[(int)*str] == 0)
		{
			flag = 1;
			i++;
		}
		else if ((g_charset[(int)*str] == 1) && flag == 1)
			break ;
		str++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int		size;
	int		i;

	i = 0;
	while (*charset != '\0')
	{
		g_charset[(int)(*charset)] = 1;
		charset++;
	}
	g_charset[0] = 1;
	splitted = ft_mk_split(str);
	while (*str != '\0')
	{
		if (g_charset[(int)*str] == 0)
		{
			size = return_size(str);
			splitted[i++] = save_str(&str, size);
			continue ;
		}
		str++;
	}
	splitted[g_no] = 0;
	return (splitted);
}
