/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 23:45:43 by taehokim          #+#    #+#             */
/*   Updated: 2020/07/04 16:27:47 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	rush_get_char(int am, int bm)
{
	if (bm && am)
	{
		return ('o');
	}
	else if (bm)
	{
		return ('-');
	}
	else if (am)
	{
		return ('|');
	}
	return (' ');
}

char	rush_pass_char(int ai, int bi, int a, int b)
{
	int am;
	int bm;

	am = 0;
	bm = 0;
	if (ai == 0 || ai == a - 1)
	{
		am = 1;
	}
	if (bi == 0 || bi == b - 1)
	{
		bm = 1;
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
