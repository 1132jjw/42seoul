/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:50:38 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/22 17:50:39 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_check_same(int *tab, int length, int *i)
{
	*i = 0;
	while (*i < length - 1)
	{
		if (tab[*i] != tab[*i + 1])
			break ;
		*i++;
	}
}

int		ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
	int	flag;

	flag = 1;
	ft_check_same(tab, length, &i);
	if (f(tab[i], tab[i + 1] > 0) && (i != length - 1))
	{
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				flag *= 0;
			i++;
		}
	}
	else if (f(tab[i], tab[i + 1] < 0) && (i != length - 1))
	{
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1] > 0))
				flag *= 0;
			i++;
		}
	}
	return (flag);
}
