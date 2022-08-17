/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 21:02:22 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/19 21:02:26 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_PARSE_H
# define DICT_PARSE_H

# include "rush02_header.h"

void	put_value(char *value_nb, t_dict *save);
void	put_key(char *nb, t_dict *save);
void	put_key_value(t_dict *dict, char *line);
t_dict	*mk_dict(char *dict_file, int *idx);
t_dict	*parse(int fd, char *dict_file);

#endif
