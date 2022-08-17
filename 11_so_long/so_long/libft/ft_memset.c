/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:37:49 by jeujeon           #+#    #+#             */
/*   Updated: 2020/10/09 12:12:55 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	int				i;
	unsigned char	chr;
	unsigned char	*p;

	p = ptr;
	i = 0;
	chr = value;
	if ((int)ft_strlen(ptr) < i)
		return (0);
	while (i < (int)num)
		p[i++] = chr;
	return (p);
}
