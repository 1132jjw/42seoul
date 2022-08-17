/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:19:20 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/20 15:08:56 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

typedef struct	s_phil
{
	char	*name;
	int		*fork;
	int		num;
	struct timeval start;
	struct timeval end;
}				t_phil;

# endif
