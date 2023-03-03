/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:17:38 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/03 18:38:45 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_table_utils(t_philo *philo)
{
	printf("%ld %d has taken a fork\n%ld %d has taken a fork\n",
		ft_current_time(philo->data->first_meal), philo->index,
		ft_current_time(philo->data->first_meal), philo->index);
}

void	lock_fork(pthread_mutex_t *l_fork, pthread_mutex_t *r_fork, int last)
{
	if (last)
	{
		pthread_mutex_lock(r_fork);
		pthread_mutex_lock(l_fork);
	}
	else
	{
		pthread_mutex_lock(l_fork);
		pthread_mutex_lock(r_fork);
	}
}
