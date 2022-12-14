/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:42:02 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/16 19:44:13 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if (str[i] > 'Z' || str[i] < 'A')
			j = j * 0;
		i++;
	}
	return (j);
}
