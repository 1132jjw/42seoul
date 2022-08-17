/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   study.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:18:59 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 17:17:01 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

float time_diff(struct timeval *start, struct timeval *end);

int	cnt;
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void	*t_function(void *data)
{
	float time;
	t_phil *phil;

	phil = (t_phil *)data;
	while (cnt < 10)
	{
		printf("%s %d\n", phil->name, cnt);
		cnt++;
		usleep(100);
	}
	// gettimeofday(&phil->end, NULL);
	// time = time_diff(&phil->start, &phil->end);
	// printf("time diff %f\n", time * 1000);
	return (0);
}

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int	main(void)
{
	t_phil			*phil;
	pthread_t		p_thread[2];
	struct timeval	start;
    struct timeval	end;
	int				thr_id;
	int				status;
	char		p1[] = "thread_1";
	char		p2[] = "thread_2";
	char		pm[] = "thread_m";

	phil = malloc(sizeof(t_phil));
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	phil->name = p1;
	phil->num = 0;
	// pthread_mutex_lock(&mutex1);
	gettimeofday(&phil->start, NULL);
	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)phil);
	if (thr_id < 0)
	{
		perror("thread create error: ");
		exit(0); 
	}
	phil->name = p2;
	phil->num = 1;
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)phil);
	if (thr_id < 0)
	{
		perror("thread create error :");
		exit(0);
	}
	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	return (0);
}
