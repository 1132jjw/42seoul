/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:10:33 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/09 19:52:10 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int a;

	a = 1;
	i = 0;
	if (power < 0)
		return (0);
	while (i < power)
	{
		a = a * nb;
		i++;
	}
	return (a);
}
