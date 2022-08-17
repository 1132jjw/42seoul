/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:55:42 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/19 20:55:46 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include "rush02_header.h"

char			*ft_strncpy(char *dest, char *src, int size);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcat(char *dest, char *src);
int				ft_strlen(char *str);
char			**ft_split(char *str, char *charset);
void			ft_putstr(char *str);
#endif
