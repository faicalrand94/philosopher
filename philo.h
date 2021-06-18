/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:02:03 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/18 19:15:55 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
# include <stdlib.h>
  #include <sys/time.h>

typedef struct s_sort
{
	int		i;
	int		j;
	int		pos;
	int		min;
	int		swap;
}					t_sort;


#endif