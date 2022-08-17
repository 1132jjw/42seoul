/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:37:39 by jeujeon           #+#    #+#             */
/*   Updated: 2020/10/15 11:40:14 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (0);
	s = (unsigned char *)src;
	tmp = (unsigned char *)dest;
	if (tmp <= s)
	{
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += n;
		s += n;
		while (n--)
			*--tmp = *--s;
	}
	return (dest);
}
