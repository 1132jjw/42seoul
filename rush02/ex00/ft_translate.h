/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:19:47 by mcho              #+#    #+#             */
/*   Updated: 2020/07/19 21:05:28 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANSLATE_H
# define FT_TRANSLATE_H

# include "rush02_header.h"

char	*ft_pow(int n, char pow_10000[]);
int		useful(char *str);
void	ft_translate(char *str, int cnt, char pow_1000[], t_dict *dict_array);
void	ft_read_argument(char *str, char pow_1000[], t_dict *dict_array);
int		fint_dict(char *str, t_dict *dict_array);

#endif
