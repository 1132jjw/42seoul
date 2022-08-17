/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:27:30 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/06 15:27:32 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int x, int y)
{
	int i1;
	int i2;
	int j1;
	int j2;

	i1 = x / 10;
	i2 = x % 10;
	j1 = y / 10;
	j2 = y % 10;
	ft_putchar(i1 + 48);
	ft_putchar(i2 + 48);
	ft_putchar(' ');
	ft_putchar(j1 + 48);
	ft_putchar(j2 + 48);
	if (!(x == 98 && y == 99))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i < 99)
	{
		j = i;
		while (j < 99)
		{
			j++;
			ft_print_result(i, j);
		}
		i++;
	}
}
