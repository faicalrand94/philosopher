/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:11:06 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/30 21:24:28 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*initial_ph(void)
{
	t_philo	*ph;

	ph = malloc(sizeof(t_philo));
	return (ph);
}

int	check_die(t_philo *ph)
{
	struct timeval		tv;
	struct timezone		tz;
	int					i;
	int					k;

	i = -1;
	while (1)
	{
		if (ph->time_each_eat >= (ph->nbr_eat * ph->nbr_ph))
			return (0);
		k = -1;
		while (++k < ph->nbr_ph)
		{		
			gettimeofday(&tv, NULL);
			if (!ph->p[k]->iseating
				&& (((tv.tv_usec) + (tv.tv_sec * 1000000))
					- ph->p[k]->last_time_eat) >= (ph->p[k]->time_to_die))
			{
				ft_print2("died", ph->p[k]->id, 1, ph->p[k]);
				return (0);
			}
			usleep(10);
		}
	}
	return (1);
}

void	loop_creat_thread(t_philo *ph)
{
	struct timeval	tv;
	struct timezone	tz;
	int				i;

	i = -1;
	while (++i < ph->nbr_ph)
	{
		gettimeofday(&tv, &tz);
		ph->p[i]->start_time = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
		ph->p[i]->last_time_eat = (tv.tv_usec) + (tv.tv_sec * 1000000);
		pthread_create(&ph->p1[i], NULL, philosopher, ph->p[i]);
		usleep(100);
	}
}

void	get_args_cnt(t_philo *ph)
{
	int	k;

	ph->p = malloc(sizeof(t_philosopher *) * ph->nbr_ph);
	k = -1;
	while (++k < ph->nbr_ph)
	{
		ph->p[k] = malloc(sizeof(t_philosopher));
		ph->p[k]->id = k + 1;
		ph->p[k]->nbr_ph = ph->nbr_ph;
		ph->p[k]->p = ph->p1;
		ph->p[k]->mut = ph->mut;
		ph->p[k]->message = &ph->message;
		ph->p[k]->time_to_die = ph->time_to_die * 1000;
		ph->p[k]->time_to_eat = ph->time_to_eat;
		ph->p[k]->time_to_sleep = ph->time_to_sleep;
		ph->p[k]->time_each_eat = &ph->time_each_eat;
	}
}

void	get_args(t_philo *ph, char **av, int ac)
{
	int	i;

	ph->nbr_ph = atoi(av[1]);
	ph->time_to_die = atoi(av[2]);
	ph->time_to_eat = atoi(av[3]);
	ph->time_to_sleep = atoi(av[4]);
	if (ac == 6)
		ph->nbr_eat = atoi(av[5]);
	else
		ph->nbr_eat = -2;
	ph->time_each_eat = 0;
	ph->p1 = malloc(sizeof(pthread_t) * ph->nbr_ph);
	i = -1;
	ph->mut = malloc(sizeof(pthread_mutex_t) * ph->nbr_ph);
	pthread_mutex_init(&ph->message, NULL);
	while (++i < ph->nbr_ph)
		pthread_mutex_init(&ph->mut[i], NULL);
	get_args_cnt(ph);
}
