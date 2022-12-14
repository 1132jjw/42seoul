/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:48:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/19 15:53:35 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	exception(int argc, char *map_file)
{
	int	file_len;

	if (argc != 2)
		return (ERROR);
	file_len = ft_strlen(map_file);
	if (ft_strncmp(&(map_file[file_len - 4]), ".ber", 4) != 0)
		return (ERROR);
	return (0);
}
