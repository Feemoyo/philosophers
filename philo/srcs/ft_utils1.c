/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:55:01 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/02 19:15:52 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_end(long time, t_philo *philo)
{
	long	last_eat;

	last_eat = 0;
	pthread_mutex_lock(philo->data->m_lock);
	last_eat = philo->last_meal;
	pthread_mutex_unlock(philo->data->m_lock);
	if (time - last_eat > philo->data->to_die)
		return (true);
	return (false);
}

static void	ft_rip(t_philo *philo)
{
	pthread_mutex_lock(philo->data->rip);
	philo->data->death = true;
	pthread_mutex_unlock(philo->data->rip);
}

void	ft_hungry(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->data->rip);
	printf("%ld %d has taken a fork\n", ft_current_time(philo->data->first_meal),
		philo->index);
	pthread_mutex_unlock(philo->data->rip);
	pthread_mutex_unlock(philo->r_fork);
	ft_ms_sleep(philo->data->to_die);
	pthread_mutex_lock(philo->data->rip);
	printf("%ld %d died\n", ft_current_time(philo->data->first_meal),
		philo->index);
	pthread_mutex_unlock(philo->data->rip);
	return ;
}

int	ft_starve(t_philo *philo)
{
	long	time;
	int		i;

	i = 0;
	time = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_mutex_lock(philo->data->t_lock);
		time = ft_current_time(philo->data->first_meal);
		pthread_mutex_unlock(philo->data->t_lock);
		if (ft_end(time, &philo[i]))
		{
			pthread_mutex_lock(philo->data->rip);
			printf("%ld %d died\n",
				ft_current_time(philo->data->first_meal), philo->index);
			pthread_mutex_unlock(philo->data->rip);
			ft_rip(&philo[i]);
			return (true);
		}
		i++;
	}
	return (false);
}

int	ft_dinner_is_over(t_philo *philo)
{
	int	i;
	int	full;

	i = 0;
	full = 0;
	while (i < philo->data->nbr_philo)
	{
		if (ft_fed_up(philo))
			full++;
		i++;
	}
	if (full == philo->data->nbr_philo)
		return (true);
	return (false);
}
