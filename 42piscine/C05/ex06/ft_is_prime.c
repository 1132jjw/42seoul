/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:26:54 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/16 16:27:36 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	else if (nb == 3)
		return (1);
	while (i < nb / i + 1)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
