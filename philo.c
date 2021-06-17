/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:01:49 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/17 19:52:15 by fbouibao         ###   ########.fr       */
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

typedef struct s_philo
{
	int id;
	pthread_mutex_t *mut;
	pthread_mutex_t message;
	int iseating;
	int issleeping;
	int nbr_ph;
}					t_philo;
t_philo     *ph;
// void *fun(void * ikhan)
// {
//    /* for (int j = 0; j < 1000000; j++)
//     {
//         pthread_mutex_lock(&mut);
//         i++;
//         pthread_mutex_unlock(&mut);

//     }
//     return (NULL);*/
// }
void ft_print(char *m, t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->message);
	fprintf(stderr, "philo %d %s\n", i, m);
	pthread_mutex_unlock(&ph->message);
}

void *fun2(void *ikhan)
{
	// t_philo *ph = (t_philo *)ikhan;
	int  *i = (int *)ikhan;

	// if (ph->id == 1)
	// {
	
	// if (ph->id == 1)
	//     fprintf(stderr, "\x1B[31mphilosopher number %d\n", ph->id);
	// else if (ph->id == 2)
	//     fprintf(stderr, "\x1B[32mphilosopher number %d\n", ph->id);

	pthread_mutex_lock(&ph->mut[(*i - 1)]);
	pthread_mutex_lock(&ph->mut[(*i) % 2]);
	ft_print("has taking forks", ph, *i);
	ft_print("is eteing", ph, *i);
	usleep(100000);
	pthread_mutex_unlock(&ph->mut[(*i - 1)]);
	pthread_mutex_unlock(&ph->mut[(*i) % 2]);
	ft_print("is sleeping", ph, *i);
	usleep(100000);
	ft_print("thinking", ph, *i);
  

	   

	

	return (NULL);
}

// void *fun3(void * ikhan)
// {
//     // pthread_mutex_lock(&mut);
//     // i++;
//     // pthread_mutex_unlock(&mut);
//     // return (NULL);
// }

t_philo    *initial_ph()
{
	t_philo *ph;
	ph = malloc(sizeof(t_philo));
	return (ph);
}



int main(int ac, char *av[])
{
	
	pthread_t *p1;
	pthread_t p2;



if (ac > 1)
{
	int i2 = 2;
	t[0] = 0;
	t[1] = 0;
 
	ph = initial_ph();
	
	ph->nbr_ph = atoi(av[1]);
	ph->mut = malloc(sizeof(pthread_mutex_t) * ph->nbr_ph);
	pthread_mutex_init(&ph->message, NULL);
	int i;
	p1 = malloc(sizeof(pthread_t) * ph->nbr_ph);
	i = -1;
	while (++i < ph->nbr_ph)
	{
		pthread_mutex_init(&ph->mut[i], NULL);
	}
	
	// while (1)
	// {
		
		i = 0;
		while (++i <= ph->nbr_ph)
		{
			ph->id = i;
			pthread_create(&p1[i - 1], NULL, fun2, &i);
		    // pthread_join(p1[i - 1], NULL);
		}
		i = 0;
		 while (++i <= ph->nbr_ph)
        {
            // ph->id = i;
            // pthread_create(&p1[i - 1], NULL, fun2, ph);
          int k = pthread_join(p1[i - 1], NULL);
		  printf("join == [%d] i == [%d]\n", k, i);
        }

	// }
}
	
	

	//pthread_mutex_destroy(&mut);
	return (0);
}