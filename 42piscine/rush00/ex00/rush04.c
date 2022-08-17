/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 23:45:43 by taehokim          #+#    #+#             */
/*   Updated: 2020/07/05 14:45:26 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	rush_get_char(int am, int bm)
{
	if (am * bm == 1)
	{
		return (' ');
	}
	else if (am == 1 || bm == 1)
	{
		return ('B');
	}
	else if (am + bm == 2)
	{
		return ('C');
	}
	return ('A');
}

char	rush_pass_char(int ai, int bi, int a, int b)
{
	int am;
	int bm;

	am = 1;
	bm = 1;
	if (ai == 0)
	{
		am = 0;
	}
	else if (ai == a - 1)
	{
		am = 2;
	}
	if (bi == 0)
	{
		bm = 0;
	}
	else if (bi == b - 1)
	{
		bm = 2;
	}
	return (rush_get_char(am, bm));
}

void	rush(int a, int b)
{
	int		ai;
	int		bi;
	char	c;

	bi = 0;
	while (bi < b)
	{
		ai = 0;
		while (ai < a)
		{
			c = rush_pass_char(ai, bi, a, b);
			ft_putchar(c);
			ai++;
		}
		ft_putchar('\n');
		bi++;
	}
}
