/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:20:15 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/16 19:45:05 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(unsigned char s)
{
	int a;
	int b;

	a = s;
	b = a / 16;
	a = a % 16;
	if (b < 10)
		ft_putchar(b + '0');
	else
		ft_putchar(b + 87);
	if (a < 10)
		ft_putchar(a + '0');
	else
		ft_putchar(a + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			ft_print_result(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
