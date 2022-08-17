/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:48:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/16 17:58:10 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
