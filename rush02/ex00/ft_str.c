/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 09:41:46 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/19 20:48:20 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_header.h"

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	return (s1[idx] - s2[idx]);
}

char	*ft_strncpy(char *dest, char *src, int size)
{
	int		idx;

	idx = 0;
	while (src[idx] && idx < size)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int idx;
	unsigned int idx1;

	idx = 0;
	idx1 = 0;
	while (dest[idx] != '\0')
		idx++;
	while (src[idx1] != '\0')
	{
		dest[idx++] = src[idx1++];
	}
	dest[idx] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int size;

	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
