/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:38:39 by jeujeon           #+#    #+#             */
/*   Updated: 2020/10/16 17:39:35 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	big_len;
	size_t	little_len;

	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	i = 0;
	j = 0;
	if (big_len < little_len)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && i < big_len)
	{
		while (big[i + j] == little[j] && j < little_len)
			j++;
		if (j == little_len && (i + j) <= len)
			return ((char *)&big[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
