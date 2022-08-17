/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:38:07 by jeujeon           #+#    #+#             */
/*   Updated: 2020/11/05 12:09:45 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(joined = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] && s1 != 0)
		joined[i] = s1[i];
	while (s2[++j] && s2 != 0)
		joined[i + j] = s2[j];
	joined[i + j] = 0;
	free((char *)s1);
	return (joined);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	c = s;
	i = 0;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	if (!(dup = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
