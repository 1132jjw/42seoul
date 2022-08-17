/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:06:38 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/21 19:08:06 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char				*ft_strcpy_tab(char *src)
{
	char			*dest;
	int				i;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*result;
	int				index;

	index = 0;
	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	while (index < ac)
	{
		result[index].str = av[index];
		result[index].copy = ft_strcpy_tab(av[index]);
		result[index].size = ft_strlen(av[index]);
		index++;
	}
	result[index].str = 0;
	result[index].copy = 0;
	result[index].size = 0;
	return (result);
}
