/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:38:16 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:11:48 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = ft_strlen(dest);
	j = 0;
	k = ft_strlen(src);
	if (size == 0)
		return (k);
	while (src[j] && i + j < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (size < i)
		return (k + size);
	else
	{
		dest[i + j] = '\0';
		return (i + k);
	}
}
