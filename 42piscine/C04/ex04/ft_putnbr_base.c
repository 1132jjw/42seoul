/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:31:32 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/18 22:15:12 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_space(char c)
{
	if ((c == '\t' || c == '\n' || c == '\v' ||\
	c == '\f' || c == '\r' || c == 32))
		return (1);
	return (0);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = 0;
		i++;
	}
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		basenb;
	long	a;

	a = nbr;
	basenb = 0;
	while (base[basenb] != '\0')
		basenb++;
	if (check_base(base))
	{
		if (a < 0)
		{
			a = -a;
			ft_putchar('-');
		}
		if (a >= basenb)
		{
			ft_putnbr_base(a / basenb, base);
			ft_putchar(base[a % basenb]);
		}
		else
			ft_putchar(base[a % basenb]);
	}
	else
		return ;
}
