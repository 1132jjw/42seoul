/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:55:53 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/19 21:04:12 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "rush02_header.h"

void	swap(t_dict *now_arr, t_dict *next_arr);
int		ft_numcmp(char *s1, char *s2);
void	ft_sort(t_dict *dict_arr);

#endif
