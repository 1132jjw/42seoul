/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:47:33 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/16 16:37:21 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime1(int nbr)
{
	int j;

	j = 2;
	if (nbr == 2)
		return (1);
	else if (nbr == 3)
		return (1);
	while (j < (nbr / j) + 1)
	{
		if (nbr % j == 0)
			return (0);
		j++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (1)
	{
		if (nb % 2 == 0)
		{
			nb++;
			continue;
		}
		else if (ft_is_prime1(nb))
			return (nb);
		nb++;
	}
	return (0);
}
