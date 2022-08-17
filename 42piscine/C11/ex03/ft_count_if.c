/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:26:23 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/22 17:26:24 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int(*f)(char*))
{
	int i;
	int j;

	i = 0;
	j= 0;
	while (i < length)
	{
		if (f(tab[i]))
		{
			while (tab[i][j])
				j++;
		}
		i++;
	}
	return (j);
}
