/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:38:33 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:10:35 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (src1[i] == 0 || src2[i] == 0)
			return ((int)(src1[i] - src2[i]));
		if (src1[i] != src2[i])
			return ((int)(src1[i] - src2[i]));
		i++;
	}
	return (0);
}
