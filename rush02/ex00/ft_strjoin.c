/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <rnfxl92@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:19:03 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/12 21:03:47 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02_header.h"

int		ft_return_size(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*char_allocator(char *sep, char **strs, int size)
{
	char		*rtn;
	long long	sp_len;
	long long	sr_len;
	long long	cnt[2];

	cnt[0] = 0;
	sr_len = 0;
	sp_len = 0;
	while (cnt[0]++ < size)
	{
		cnt[1] = 0;
		while (strs[cnt[0] - 1][cnt[1]] != '\0')
		{
			sr_len++;
			cnt[1]++;
		}
	}
	cnt[0] = 0;
	while (*sep != '\0')
	{
		sp_len++;
		sep++;
	}
	rtn = (char *)malloc((sp_len * (size - 1) + sr_len + 1) * sizeof(char));
	return (rtn);
}

void	my_strcat(char *dest, char *src, char *sep)
{
	while (*dest != '\0')
		(dest)++;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		(dest)++;
	}
	while (*sep != '\0')
	{
		*dest = *sep;
		sep++;
		(dest)++;
	}
	*dest = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*rtn;
	char	*temp;
	int		cnt;

	if (size == 0)
	{
		rtn = (char *)malloc(1);
		rtn[0] = '\0';
		return (rtn);
	}
	rtn = char_allocator(sep, strs, size);
	temp = rtn;
	temp[0] = 0;
	cnt = 0;
	while (cnt < size - 1)
		my_strcat(temp, strs[cnt++], sep);
	my_strcat(temp, strs[cnt], "");
	return (rtn);
}
