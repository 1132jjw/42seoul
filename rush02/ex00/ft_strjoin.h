/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 22:25:56 by jeujeon           #+#    #+#             */
/*   Updated: 2020/07/19 22:25:57 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRJOIN_H
# define FT_STRJOIN_H

# include "rush02_header.h"

int		ft_return_size(char **str);
char	*char_allocator(char *sep, char **strs, int size);
char	*ft_strjoin(int size, char **strs, char *sep);
void	my_strcat(char *dest, char *src, char *sep);

#endif
