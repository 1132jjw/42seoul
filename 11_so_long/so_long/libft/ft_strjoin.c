/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:38:10 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:06:41 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_joined(int i, int j, char const *s1, char const *s2)
{
	char	*joined;

	joined = malloc(sizeof(char) * (i + j + 1));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && s1 != 0)
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j] && s2 != 0)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = 0;
	return (joined);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return ((char *)s2);
	else if (s2 == 0)
		return ((char *)s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	joined = make_joined(i, j, s1, s2);
	if (!joined)
		return (NULL);
	return (joined);
}
