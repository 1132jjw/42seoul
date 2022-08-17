/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:02:44 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/15 15:02:46 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			else if (s1[i] == s2[i])
				return (0);
			else
				return (0);
		}
		i++;
	}
	if (s1[i] > s2[i])
		return (1);
	else if (s1[i] == s2[i])
		return (0);
	else
		return (-1);
}

int		main(int argc, char **argv)
{
	int i;
	int	j;
	char*tmp;

	j = 1;
	while (j)
	{
		i = 0;
		j = 0;
		while (++i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				j = 1;
			}
		}
	}
	i = 0;
	while (++i < argc)
		ft_print_result(argv[i]);
}
