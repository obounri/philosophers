#ifndef PHILO_H
# define PHILO_H

#include "../utils/libft/libft.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "unistd.h"
#include <sys/time.h>

typedef struct s_table
{
    struct s_philo  *philos;
    struct s_fork   *forks;
    pthread_mutex_t std_o;
	long int t_start;
    int n_philos;
    int t_die;
    int t_eat;
    int t_sleep;
    int n_must_eat;
    int death;
}   t_table;

typedef struct s_philo
{
    struct s_table *table;
    pthread_t philo;
    long int last_t_ate;
    int id_philo;
    int n_ate;
}   t_philo;

typedef struct s_fork
{
    pthread_mutex_t fork;
    int used;
}   t_fork;

int         init_store_options(t_table *options, char **av);
long int    curr_time();
void        ft_error(char *error);
void        status(t_table *table, int id_philo, char *string);
void        *routine(void *data);
void        *check_death(void *data);
#endif