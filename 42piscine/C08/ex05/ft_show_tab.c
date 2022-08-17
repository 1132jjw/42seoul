/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:55:35 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/21 18:55:51 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_putnb(int nb)
{
	while (nb)
	{
		if (nb > 9)
		{
			ft_putchar(nb % 10 + '0');
			nb /= 10;
		}
		else
		{
			ft_putchar(nb + '0');
			ft_putchar('\n');
			break ;
		}
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnb(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}
