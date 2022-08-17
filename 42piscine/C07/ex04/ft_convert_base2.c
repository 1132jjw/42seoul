/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:50:10 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/18 21:16:47 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_base_len(char *base);
int		check_base(char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_return_nb_size(int nb, int base_len)
{
	int		nb_size;
	long	a;

	if (nb == 0)
		return (1);
	a = nb;
	if (nb < 0)
		a *= -1;
	nb_size = 0;
	while (a)
	{
		a = a / base_len;
		nb_size++;
	}
	if (nb < 0)
		return (nb_size + 1);
	else
		return (nb_size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	base_from_nb;
	int		base_len;
	int		nb_size;
	char	*base_to_nb;
	int		index;

	base_from_nb = ft_atoi_base(nbr, base_from);
	base_len = ft_base_len(base_to);
	nb_size = ft_return_nb_size(base_from_nb, base_len);
	index = (base_from_nb < 0) ? 1 : 0;
	if (!check_base(base_to) || !(check_base(base_from)))
		return (0);
	base_to_nb = (char *)malloc(sizeof(char) * (nb_size + 1));
	if (base_from_nb < 0)
		base_to_nb[0] = '-';
	if (base_from_nb < 0)
		base_from_nb *= -1;
	while (index < nb_size)
	{
		base_to_nb[nb_size - index++ -
		!(base_to_nb[0] == '-')] = base_to[base_from_nb % base_len];
		base_from_nb = base_from_nb / base_len;
	}
	base_to_nb[nb_size] = '\0';
	return (base_to_nb);
}
