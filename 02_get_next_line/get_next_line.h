/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:48:26 by jeujeon           #+#    #+#             */
/*   Updated: 2020/12/14 16:09:49 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define OPEN_MAX 4096
# define BUFFER_SIZE 3

char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
int		get_next_line(int fd, char **line);

#endif
