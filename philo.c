/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:01:49 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/29 19:05:46 by fbouibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define ttd  "600"
#define tte  "100"
#define tts  "100"
int i = 0;
int d = 0;
int t[2];
// pthread_mutex_t mut;
pthread_mutex_t die;



typedef struct s_philosopher
{
	int id;
	pthread_t *p;
	pthread_mutex_t *mut;
	pthread_mutex_t message;
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
t_philo     *ph;
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
void	ft_putnbr_fd(int nbr, int fd)
{
	unsigned int	num;

	num = nbr;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		num = num * -1;
	}
	if (num < 10)
	{
		ft_putchar_fd(num + 48, fd);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + 48, fd);
	}
}

size_t get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}
void ft_print2(char *m, t_philo *ph, int i, int c, t_philosopher *p)
{
	struct timeval tv;
    struct timezone tz;
    size_t time;
    size_t time2;
    size_t res;

	pthread_mutex_lock(&ph->message);
	/*if (c == 1)
		ft_putstr_fd("\x1B[37m", 1);
	else if (c == 2)
		ft_putstr_fd("\x1B[37m", 1);
	else if (c == 3)
		ft_putstr_fd("\x1B[33m", 1);
	else if (c == 4)
		ft_putstr_fd("\x1B[34m", 1);
	else if (c == 5)
		ft_putstr_fd("\x1B[35m", 1);
	else if (c == 6)
		ft_putstr_fd("\x1B[36m", 1);*/
	gettimeofday(&tv,&tz);
    time = (tv.tv_usec / 1000) + (tv.tv_sec * 1000) - p->start_time;
	ft_putnbr_fd(time, 1);
	// fprintf(stderr, "%zu " , time);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd("philo ", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(m, 1);
	ft_putstr_fd("\n", 1);
	exit(0);
	pthread_mutex_unlock(&ph->message);
}
void ft_print(char *m, t_philo *ph, int i, int c, t_philosopher *p)
{
	struct timeval tv;
    struct timezone tz;
    size_t time;
    size_t time2;
    size_t res;

	pthread_mutex_lock(&ph->message);
	/*if (c == 1)
		ft_putstr_fd("\x1B[37m", 1);
	else if (c == 2)
		ft_putstr_fd("\x1B[37m", 1);
	else if (c == 3)
		ft_putstr_fd("\x1B[33m", 1);
	else if (c == 4)
		ft_putstr_fd("\x1B[34m", 1);
	else if (c == 5)
		ft_putstr_fd("\x1B[35m", 1);
	else if (c == 6)
		ft_putstr_fd("\x1B[36m", 1);*/
	gettimeofday(&tv,&tz);
    time = (tv.tv_usec / 1000) + (tv.tv_sec * 1000) - p->start_time;
	ft_putnbr_fd(time, 1);
	// fprintf(stderr, "%zu " , time);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd("philo ", 1);
	ft_putnbr_fd(i, 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(m, 1);
	ft_putstr_fd("\n", 1);
	pthread_mutex_unlock(&ph->message);
}
void    mysleep(int usecond)
{
    struct timeval tv;
    size_t time;
    gettimeofday(&tv, NULL);
    time = get_time();

    //res = time;
    usleep((usecond - 10) * 1000);
    
    while ((get_time() - time) < usecond)
    {
    }
    // ft_putnbr_fd(time, 1);
    // ft_putstr_fd("\n", 1);
    // ft_putnbr_fd(time2, 1);
    // ft_putstr_fd("\n", 1);
    




    // printf("result ==> %lu", res);

}
void *fun2(void *ag)
{
	t_philosopher  *p = (t_philosopher *)ag;
	struct timeval tv;
    struct timezone tz;
    size_t time;
    size_t time2;
    size_t res;

	p->iseating = 0;
	while (1)
	{
	pthread_mutex_lock(&p->mut[(p->id - 1)]);
	ft_print("has taking a fork", ph, p->id, 6, p);
	pthread_mutex_lock(&p->mut[(p->id) % p->nbr_ph]);
	ft_print("has taking a fork", ph, p->id, 2, p);
	p->iseating = 1;
	ft_print("is eating", ph, p->id, 3, p);	
	(*p->time_each_eat)++;
	gettimeofday(&tv, NULL);
    p->last_time_eat = (tv.tv_usec) + (tv.tv_sec * 1000000);
	mysleep(p->time_to_eat);
	pthread_mutex_unlock(&p->mut[(p->id) % p->nbr_ph]);
	pthread_mutex_unlock(&p->mut[(p->id - 1)]);
	ft_print("is sleeping", ph, p->id, 4, p);
	p->iseating = 0;
	mysleep(p->time_to_sleep);    
	ft_print("thinking", ph, p->id, 5, p);
}
	   

	

	return (NULL);
}

// void *fun3(void * ikhan)
// {
//     // pthread_mutex_lock(&mut);
//     // i++;
//     // pthread_mutex_unlock(&mut);
//     // return (NULL);
// }
long long get_time_mic()
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000000 + tv.tv_usec);
}

t_philo    *initial_ph()
{
	t_philo *ph;
	ph = malloc(sizeof(t_philo));
	return (ph);
}



int main(int ac, char *av[])
{


    struct timeval tv;
    struct timezone tz;
    size_t time;


	int k;
		int i;


	if (ac > 4)
	{
		int i2 = 2;


		ph = initial_ph();
		ph->nbr_ph = atoi(av[1]);
		ph->time_to_die = atoi(av[2]);
		ph->time_to_eat = atoi(av[3]);
		ph->time_to_sleep = atoi(av[4]);
		if (ac == 6)
		{
			ph->nbr_eat = atoi(av[5]);
		}
		else
			ph->nbr_eat = -2;
		ph->time_each_eat = 0;
		ph->p1 = malloc(sizeof(pthread_t) * ph->nbr_ph);
		i = -1;	
		ph->mut = malloc(sizeof(pthread_mutex_t) * ph->nbr_ph);
		pthread_mutex_init(&ph->message, NULL);
		while (++i < ph->nbr_ph)
			pthread_mutex_init(&ph->mut[i], NULL);
		ph->p = malloc(sizeof(t_philosopher *) * ph->nbr_ph);
		k = -1;
		while (++k < ph->nbr_ph)
		{
			ph->p[k] = malloc(sizeof(t_philosopher));
			ph->p[k]->id = k + 1;
			ph->p[k]->nbr_ph = ph->nbr_ph;
			ph->p[k]->p = ph->p1;
			ph->p[k]->mut = ph->mut;
			ph->p[k]->message = ph->message;
			ph->p[k]->time_to_die = ph->time_to_die * 1000;
			ph->p[k]->time_to_eat = ph->time_to_eat;
			ph->p[k]->time_to_sleep = ph->time_to_sleep;
			ph->p[k]->time_each_eat = &ph->time_each_eat;
		}
		i = -1;
		while (++i < ph->nbr_ph)
		{
			gettimeofday(&tv,&tz);
			ph->p[i]->start_time = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
			ph->p[i]->last_time_eat = (tv.tv_usec) + (tv.tv_sec * 1000000);
			pthread_create(&ph->p1[i], NULL, fun2, ph->p[i]);
			usleep(100);
		}
		i = -1;
		while (1)
		{
			if (ph->time_each_eat >= (ph->nbr_eat * ph->nbr_ph))
			{
				return (0);
			}
			int k = -1;
			while (++k < ph->nbr_ph)
			{		
				gettimeofday(&tv,NULL);
				if (!ph->p[k]->iseating && (((tv.tv_usec) + (tv.tv_sec * 1000000)) - ph->p[k]->last_time_eat) >= (ph->p[k]->time_to_die))
				{
					ft_print2("died", ph, ph->p[k]->id, 1, ph->p[k]);
					return (0);
				}
				usleep(10);
			}
		}	
		i = 0;
		while (++i <= ph->nbr_ph)
			k = pthread_join(ph->p1[i - 1], NULL);
	}
	return (0);
}
