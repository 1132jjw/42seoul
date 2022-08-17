/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:38:29 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/16 19:44:07 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 'a' || str[i] > 'z')
			j = j * 0;
		i++;
	}
	return (j);
}
