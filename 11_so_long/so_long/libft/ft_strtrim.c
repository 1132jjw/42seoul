/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:38:51 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:11:32 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_set(char const c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*make_tmp(char const *s1, int start, int end)
{
	char	*tmp;
	int		i;

	i = 0;
	if (start > end)
	{
		tmp = calloc(1, sizeof(char));
		if (!tmp)
			return (NULL);
	}
	else
	{
		tmp = ft_calloc((end - start + 2), sizeof(char));
		if (!tmp)
			return (NULL);
		while (start <= end)
			tmp[i++] = s1[start++];
	}
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		start;
	int		end;

	if (s1 == 0)
		return (0);
	else if (set == 0)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (check_set(s1[start], set) && start <= end)
		start++;
	while (end >= 0 && check_set(s1[end], set))
		end--;
	tmp = make_tmp(s1, start, end);
	if (!tmp)
		return (0);
	return (tmp);
}
