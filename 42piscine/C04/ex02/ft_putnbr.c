/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:06:21 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/18 22:15:01 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long a;

	a = nb;
	if (a < 0)
	{
		a = -a;
		ft_putchar('-');
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putchar(a % 10 + 48);
	}
	else
		ft_putchar(a % 10 + 48);
}
