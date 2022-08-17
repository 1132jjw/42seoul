/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_header.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:58:19 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/19 21:05:35 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_HEADER_H
# define RUSH02_HEADER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "dict_struct.h"
# include "ft_str.h"
# include "ft_translate.h"
# include "dict_parse.h"
# include "ft_sort.h"
# include "ft_strjoin.h"

int		g_error;
int		g_dict_len;
int		g_flag;
char	g_char;
char	g_answer[1000];

#endif
