/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:05:34 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/18 20:01:31 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int index;
	int find_position;

	index = 0;
	if (to_find[index] == '\0')
		return (str);
	while (str[index])
	{
		find_position = 0;
		while (str[index + find_position] == to_find[find_position])
		{
			if (to_find[find_position + 1] == '\0')
				return (str + index);
			find_position++;
		}
		index++;
	}
	return (0);
}
