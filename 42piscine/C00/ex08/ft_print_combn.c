/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:24:17 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/10 10:26:40 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int *a, int size)
{
	int i;
	int o;

	o = 1;
	i = 1;
	while (i < size)
	{
		if (a[i] <= a[i - 1])
			o = 0;
		i++;
	}
	i = 0;
	if (o)
	{
		while (i < size)
		{
			ft_putchar(a[i] + 48);
			i++;
		}
		if (a[0] < (10 - size))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_bign(int *a, int size)
{
	int i;

	ft_print_result(a, size);
	a[size - 1]++;
	i = size;
	while (i > 0)
	{
		i--;
		if (a[i] > 9)
		{
			a[i - 1]++;
			a[i] = 0;
		}
	}
}

void	ft_print_combn(int n)
{
	int arr[n];
	int i;

	i = 0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
	if (n == 1)
	{
		while (arr[0] < 10)
		{
			ft_putchar(arr[0] + 48);
			if (arr[0] != 9)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			arr[0]++;
		}
	}
	while (arr[0] <= (10 - n) && n > 1)
		ft_bign(arr, n);
}
