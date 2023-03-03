/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:42:36 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/03 02:28:14 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo)
{
	t_philo	*aux;

	aux = (t_philo *)philo;
	if (aux->index % 2 != 0)
		ft_ms_sleep(5);
	while (!ft_gravedigger(aux))
	{
		ft_table(aux);
		if (ft_fed_up(aux))
			return (NULL);
		pthread_mutex_lock(aux->data->rip);
		if (!aux->data->death)
			printf("%ld %d is sleeping\n",
				ft_current_time(aux->data->first_meal), aux->index);
		pthread_mutex_unlock(aux->data->rip);
		ft_ms_sleep(aux->data->to_sleep);
		pthread_mutex_lock(aux->data->rip);
		if (!aux->data->death)
			printf("%ld %d is thinking\n",
				ft_current_time(aux->data->first_meal), aux->index);
		pthread_mutex_unlock(aux->data->rip);
	}
	return (NULL);
}

int	ft_gravedigger(t_philo *philo)
{
	pthread_mutex_lock(philo->data->rip);
	if (philo->data->death == true)
	{
		pthread_mutex_unlock(philo->data->rip);
		return (true);
	}
	pthread_mutex_unlock(philo->data->rip);
	return (false);
}

int	ft_fed_up(t_philo *philo)
{
	pthread_mutex_lock(philo->data->check_m_lock);
	if (philo->eat == philo->data->nbr_meals)
	{
		pthread_mutex_unlock(philo->data->check_m_lock);
		return (true);
	}
	pthread_mutex_unlock(philo->data->check_m_lock);
	return (false);
}

void	ft_table(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	if (ft_gravedigger(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->data->rip);
	ft_table_utils(philo);
	pthread_mutex_unlock(philo->data->rip);
	pthread_mutex_lock(philo->data->m_lock);
	philo->last_meal = ft_current_time(philo->data->first_meal);
	pthread_mutex_unlock(philo->data->m_lock);
	pthread_mutex_lock(philo->data->check_m_lock);
	philo->eat++;
	pthread_mutex_unlock(philo->data->check_m_lock);
	pthread_mutex_lock(philo->data->rip);
	printf("%ld %d is eating\n",
		ft_current_time(philo->data->first_meal), philo->index);
	pthread_mutex_unlock(philo->data->rip);
	ft_ms_sleep(philo->data->to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*ft_check_dinner(void *philo)
{
	t_philo	*aux;

	aux = (t_philo *)philo;
	while (!ft_dinner_is_over(aux))
	{
		if (ft_starve(aux))
			return (NULL);
		ft_ms_sleep(1);
	}
	return (NULL);
}
