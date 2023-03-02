/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:31:59 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/02 19:09:49 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

enum e_boolean
{
	false,
	true
};

typedef struct s_data
{
	int				nbr_philo;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				current_meal;
	int				death;
	int				nbr_meals;
	long			first_meal;
	pthread_mutex_t	*m_lock;
	pthread_mutex_t	*t_lock;
	pthread_mutex_t	*rip;
	pthread_mutex_t	*check_m_lock;
	pthread_mutex_t	*print;
}				t_data;

typedef struct s_philo
{
	int				index;
	int				eat;
	long			last_meal;
	pthread_t		thread_philo;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_data			*data;
}				t_philo;

// ft_verify.c
int			ft_verify(int argc, char **argv);

// ft_utils0.c
int			ft_isnum(char **str, int argc);
int			ft_atoi(const char *str);

// ft_init_table.c
void		ft_init_data(int argc, char **argv, t_data *data);
void		ft_init_dinner(t_data *data, int nbr_philo, pthread_mutex_t **forks,
				t_philo **philo);
void		ft_begin_dinner(t_philo *philo);

// ft_time.c
long		ft_set_timer(void);
void		ft_ms_sleep(int time_in_ms);
long		ft_current_time(long start);

// ft_utils1.c
void		ft_hungry(t_philo *philo);
int			ft_starve(t_philo *philo);
int			ft_dinner_is_over(t_philo *philo);

// ft_routine.c
void		*ft_routine(void *philo);
int			ft_gravedigger(t_philo *philo);
int			ft_fed_up(t_philo *philo);
void		ft_table(t_philo *philo);
void		*ft_check_dinner(void *philo);

// ft_free.c
void		ft_free_dinner(int nbr_philo, t_philo **philo,
				pthread_mutex_t **forks);
void		ft_free_data(t_data *data);

#endif