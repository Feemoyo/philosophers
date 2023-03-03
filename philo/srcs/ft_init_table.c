/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:32:41 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/03 19:38:27 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(int argc, char **argv, t_data *data)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->to_die = ft_atoi(argv[2]);
	data->to_eat = ft_atoi(argv[3]);
	data->to_sleep = ft_atoi(argv[4]);
	data->current_meal = 0;
	data->death = false;
	if (argc == 6)
		data->nbr_meals = ft_atoi(argv[5]);
	else
		data->nbr_meals = -1;
	data->m_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	data->t_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	data->rip = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	data->check_m_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	pthread_mutex_init(data->m_lock, NULL);
	pthread_mutex_init(data->t_lock, NULL);
	pthread_mutex_init(data->rip, NULL);
	pthread_mutex_init(data->check_m_lock, NULL);
}

void	ft_init_dinner(t_data *data, int nbr_philo, pthread_mutex_t **forks,
		t_philo **philo)
{
	int	i;

	i = -1;
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * nbr_philo);
	while (++i < nbr_philo)
		pthread_mutex_init(&(*forks)[i], NULL);
	i = -1;
	*philo = (t_philo *) malloc(sizeof(t_philo) * nbr_philo);
	while (++i < nbr_philo)
	{
		(*philo)[i].last_meal = ft_set_timer();
		(*philo)[i].index = i + 1;
		(*philo)[i].eat = 0;
		(*philo)[i].l_fork = &(*forks)[i];
		(*philo)[i].r_fork = &(*forks)[i + 1];
		(*philo)[i].data = data;
	}
	i--;
	(*philo)[i].l_fork = &(*forks)[0];
	(*philo)[i].r_fork = &(*forks)[i];
}

void	ft_begin_dinner(t_philo *philo)
{
	pthread_t	the_watcher;
	int			i;

	philo->data->first_meal = ft_set_timer();
	if (philo->data->nbr_philo == 1)
		return (ft_hungry(philo));
	i = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_create(&philo[i].thread_philo, NULL, &ft_routine, &philo[i]);
		i++;
	}
	i = 0;
	pthread_create(&the_watcher, NULL, &ft_check_dinner, philo);
	while (i < philo->data->nbr_philo)
	{
		pthread_join(philo[i].thread_philo, NULL);
		i++;
	}
	pthread_join(the_watcher, NULL);
}
