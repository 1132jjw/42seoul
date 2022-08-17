/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:38:57 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:10:09 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < (int)len && start < ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
