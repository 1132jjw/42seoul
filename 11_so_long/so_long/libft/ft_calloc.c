/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:27:17 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:12:03 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*arr;
	unsigned char	*temp;
	size_t			i;

	i = 0;
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	temp = (unsigned char *)arr;
	while (i < nmemb * size)
	{
		temp[i] = 0;
		i++;
	}
	return (arr);
}
