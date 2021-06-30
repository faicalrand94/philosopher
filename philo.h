/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:02:03 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/30 21:24:20 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
# include <stdlib.h>
  #include <sys/time.h>

typedef struct s_philosopher
{
	int id;
	pthread_t *p;
	pthread_mutex_t *mut;
	pthread_mutex_t *message;
	int iseating;
	int nbr_ph;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t last_time_eat;
	int *time_each_eat;
	long long start_time;
}					t_philosopher;


typedef struct s_philo
{
	int id;
	pthread_mutex_t *mut;
	pthread_mutex_t message;
	int iseating;
	int issleeping;
	int nbr_ph;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t nbr_eat;
	t_philosopher	**p;
	int time_each_eat;
	pthread_t *p1;
}					t_philo;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void    mysleep(int usecond);
void *philosopher(void *ag);
size_t get_time();
void ft_print2(char *m, int i, int c, t_philosopher *p);
void ft_print(char *m, int i, int c, t_philosopher *p);
void	get_args(t_philo *ph, char **av, int ac);
void	loop_creat_thread(t_philo *ph);
int	check_die(t_philo *ph);
t_philo    *initial_ph();

#endif