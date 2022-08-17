/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:38:56 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/09 19:08:32 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int a;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	a = 1;
	while (nb > 0)
	{
		a *= nb;
		nb = nb - 1;
	}
	return (a);
}
