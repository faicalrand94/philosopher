/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:30:48 by fbouibao          #+#    #+#             */
/*   Updated: 2021/07/01 13:14:04 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec) + (tv.tv_sec * 1000000));
}

void	ft_print2(char *m, int i, int c, t_philosopher *p)
{
	struct timeval	tv;
	struct timezone	tz;
	size_t			time;

	pthread_mutex_lock(p->message);
	printf("\x1B[31m");
	gettimeofday(&tv, &tz);
	time = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
	printf("%zu %d %s\n", time, i, m);
	exit(0);
	pthread_mutex_unlock(p->message);
}

void	ft_print(char *m, int i, int c, t_philosopher *p)
{
	struct timeval	tv;
	struct timezone	tz;
	size_t			time;

	pthread_mutex_lock(p->message);
	gettimeofday(&tv, &tz);
	time = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
	printf("%zu %d %s\n", time, i, m);
	pthread_mutex_unlock(p->message);
}
