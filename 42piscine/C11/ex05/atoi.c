/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:11:14 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/22 21:11:16 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do-op.h"

int		ft_check(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	else
		return (0);
}

int		ft_is_blank(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||\
	str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		return (1);
	else
		return (0);
}

int		ft_is_pm(char *str, int i)
{
	if (str[i] == '+' || str[i] == '-')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int k;
	int nb;

	nb = 0;
	i = 0;
	k = 1;
	while (ft_is_blank(str, i))
		i++;
	while (ft_is_pm(str, i))
	{
		if (str[i] == '-')
			k = k * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * k);
}
