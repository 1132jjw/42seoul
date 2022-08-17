/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:16:04 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/18 21:05:28 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if ((c == '\t' || c == '\n' || c == '\v' ||\
	c == '\f' || c == '\r' || c == 32))
		return (1);
	return (0);
}

int		ft_base_len(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = 0;
		i++;
	}
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	return (1);
}

int		ft_base_check(char c, char *base, int base_len)
{
	int i;

	i = 0;
	while (i < base_len)
	{
		if (c == base[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int k;
	int nb;

	nb = 0;
	i = 0;
	k = 1;
	if (!check_base(base))
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			k = k * -1;
		i++;
	}
	while (ft_base_check(str[i], base, ft_base_len(base)))
	{
		nb = nb * ft_base_len(base);
		nb = nb + ft_base_check(str[i], base, ft_base_len(base)) - 1;
		i++;
	}
	return (nb * k);
}
