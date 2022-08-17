/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:38:46 by jeujeon           #+#    #+#             */
/*   Updated: 2020/10/16 17:15:01 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, char c)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (c == '\0' && str[i + 1] == 0)
		return ((char *)&str[i + 1]);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
