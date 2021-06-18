#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
  #include <sys/time.h>
int i = 0;
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
    for (int j = 0; j < 2000000; j++)
    {
        pthread_mutex_lock(&mut);
        i++;
        pthread_mutex_unlock(&mut);

    }
    return (NULL);
}

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

void    mysleep(int usecond)
{
    struct timeval tv;
    struct timezone tz;
    size_t time;
    size_t time2;
    size_t res;

    gettimeofday(&tv,&tz);
    time = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);

    
    usleep((usecond - 10) * 1000);
    
    // time2 = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
    // res = time2 - time;
    while (res != usecond)
    {
        gettimeofday(&tv,&tz);
        time2 = (tv.tv_usec / 1000) + (tv.tv_sec * 1000);
           res = time2 - time;
        
    }
    ft_putnbr_fd(time, 1);
    ft_putstr_fd("\n", 1);
    ft_putnbr_fd(time2, 1);
    ft_putstr_fd("\n", 1);
    




    printf("result ==> %lu", res);

}

int main()
{
    pthread_t p1;
    pthread_t p2;


    mysleep(9000);
    // pthread_mutex_init(&mut, NULL);
    // pthread_create(&p1, NULL, fun, NULL);
    // pthread_create(&p2, NULL, fun2, NULL);
    // pthread_join(p1, NULL);
    // printf("%d\n", i);
    
    // pthread_join(p2, NULL);
    // printf("%d\n", i);
    //pthread_mutex_destroy(&mut);
    return (0);
}