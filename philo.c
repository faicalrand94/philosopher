/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:01:49 by fbouibao          #+#    #+#             */
/*   Updated: 2021/06/16 20:27:33 by fbouibao         ###   ########.fr       */
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
int i = 0;
int d = 0;
pthread_mutex_t mut;

void *fun(void * ikhan)
{
    for (int j = 0; j < 1000000; j++)
    {
        pthread_mutex_lock(&mut);
        i++;
        pthread_mutex_unlock(&mut);

    }
    return (NULL);
}

void *fun2(void * ikhan)
{
    int *a = (int*)ikhan;
while (1)
{ 
    if (*a == 1)
    {
        
        pthread_mutex_lock(&mut);
        d = 1;
        usleep(100);
        pthread_mutex_unlock(&mut);
        fprintf(stderr, "\x1B[31mphilosopher number %d ==> %d\n", *a, d);
    }
    else if (*a == 2)
    {
                
        pthread_mutex_lock(&mut);
        d = 2;
        usleep(100);
        pthread_mutex_unlock(&mut);
        fprintf(stderr, "\x1B[32mphilosopher number %d ==> %d\n", *a, d);
    }
    else if (*a == 3)
    {        
        pthread_mutex_lock(&mut);
        d = 3;
        usleep(100);
        pthread_mutex_unlock(&mut);
        fprintf(stderr, "\x1B[33mphilosopher number %d ==> %d\n", *a, d);
    }
    else if (*a == 4)
    {    
        pthread_mutex_lock(&mut);
        d = 4;
        usleep(100);
        pthread_mutex_unlock(&mut);
        fprintf(stderr, "\x1B[34mphilosopher number %d ==> %d\n", *a, d);
    }
    usleep(700000);
  
}

       

    

    return (NULL);
}

void *fun3(void * ikhan)
{
    pthread_mutex_lock(&mut);
    i++;
    pthread_mutex_unlock(&mut);
    return (NULL);
}

int main()
{
    pthread_t p1;
    pthread_t p2;
    pthread_t p3;
    pthread_t p4;
    int i = 1;
    int i2 = 2;
    int i3 = 3;
    int i4 = 4;

    pthread_mutex_init(&mut, NULL);
    pthread_create(&p1, NULL, fun2, &i);
    pthread_create(&p2, NULL, fun2, &i2);
    pthread_create(&p3, NULL, fun2, &i3);
    pthread_create(&p4, NULL, fun2, &i4);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);
    //pthread_mutex_destroy(&mut);
    return (0);
}