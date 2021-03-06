/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:23:02 by obounri           #+#    #+#             */
/*   Updated: 2021/11/04 08:17:16 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_table
{
	struct s_philo	*philos;
	struct s_fork	*forks;
	pthread_t		count;
	pthread_mutex_t	std_o;
	pthread_mutex_t	philo_dead;
	long int		t_start;
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_must_eat;
	int				death;
}	t_table;

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		philo;
	pthread_mutex_t	ate;
	long int		last_t_ate;
	int				id_philo;
	int				n_ate;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
}	t_fork;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
int			init_store_options(t_table *options, char **av);
long int	curr_time(void);
void		ft_error(char *error);
void		status(t_table *table, int id_philo, char *string, int c);
void		*routine(void *data);
void		*check_death(void *data);
void		*eat_count(void *data);

#endif