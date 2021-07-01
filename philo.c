/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:01:49 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/30 21:15:31 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_philo	*ph;
	int		i;

	if (ac > 4)
	{
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
