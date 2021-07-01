/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treads.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:24:14 by fbouibao          #+#    #+#             */
/*   Updated: 2021/07/01 13:13:43 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *ag)
{
	t_philosopher	*p;
	struct timeval	tv;
	struct timezone	tz;

	p = (t_philosopher *)ag;
	p->iseating = 0;
	while (1)
	{
		pthread_mutex_lock(&p->mut[(p->id - 1)]);
		ft_print("has taken a fork", p->id, 6, p);
		pthread_mutex_lock(&p->mut[(p->id) % p->nbr_ph]);
		ft_print("has taken a fork", p->id, 2, p);
		p->iseating = 1;
		ft_print("is eating", p->id, 3, p);
		(*p->time_each_eat)++;
		gettimeofday(&tv, NULL);
		p->last_time_eat = (tv.tv_usec) + (tv.tv_sec * 1000000);
		mysleep(p->time_to_eat);
		pthread_mutex_unlock(&p->mut[(p->id) % p->nbr_ph]);
		pthread_mutex_unlock(&p->mut[(p->id - 1)]);
		ft_print("is sleeping", p->id, 4, p);
		p->iseating = 0;
		mysleep(p->time_to_sleep);
		ft_print("is thinking", p->id, 5, p);
	}
	return (NULL);
}
