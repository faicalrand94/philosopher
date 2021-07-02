/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:01:49 by fbouibao          #+#    #+#             */
/*   Updated: 2021/07/02 15:44:43 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_arg(char *av)
{
	int	i;

	i = -1;
	if (av[i + 1] == '+')
		i++;
	if (av[i + 1] < '0' || av[i + 1] > '9')
		return (1);
	while (av[++i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
	}
	return (0);
}

int	check_args(int ac, char *av[])
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (1);
	while (av[++i])
	{
		if (check_arg(av[i]))
			return (1);
	}
	return (0);
}


int	main(int ac, char *av[])
{
	t_philo	*ph;
	int		i;

	if (ac > 4)
	{
		if (check_args(ac, av))
			return (1);
		ph = initial_ph();
		get_args(ph, av, ac);
		loop_creat_thread(ph);
		if (check_die(ph) == 0)
			return (0);
		i = 0;
		while (++i <= ph->nbr_ph)
			pthread_join(ph->p1[i - 1], NULL);
	}
	return (0);
}
