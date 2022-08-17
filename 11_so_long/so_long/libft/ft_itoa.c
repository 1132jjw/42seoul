/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:35:14 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:19:52 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_str(int size, int flag, long n)
{
	char	*make;
	int		*tmp;
	int		size_tmp;

	tmp = malloc(sizeof(int) * size);
	size_tmp = size;
	make = malloc(sizeof(char) * (size + 1 + flag));
	if (flag)
		make[0] = '-';
	while (n)
	{
		tmp[--size] = (n % 10) + '0';
		n /= 10;
	}
	while (size < size_tmp)
	{
		make[size + flag] = tmp[size];
		size++;
	}
	make[size + flag] = 0;
	free(tmp);
	return (make);
}

char	*is_num_zero(void)
{
	char	*result;

	result = malloc(2 * sizeof(char));
	result[0] = '0';
	result[1] = 0;
	return (result);
}

char	*ft_itoa(int num)
{
	long	n;
	char	*result;
	int		size;
	int		flag;

	if (num == 0)
		return (is_num_zero());
	n = num;
	if (n < 0)
		flag = 1;
	else
		flag = 0;
	size = 0;
	if (n < 0)
		n *= -1;
	while (num)
	{
		num /= 10;
		size++;
	}
	result = make_str(size, flag, n);
	return (result);
}
