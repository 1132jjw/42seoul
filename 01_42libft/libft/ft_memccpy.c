/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:35:36 by jeujeon           #+#    #+#             */
/*   Updated: 2020/10/15 11:39:15 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	chr = (unsigned char)c;
	if (*s == 0)
		return (d);
	while (i < n)
	{
		if (s[i] == chr)
		{
			d[i] = s[i];
			i++;
			return (&d[i]);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
