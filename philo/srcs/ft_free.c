/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:16:12 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/01 19:17:46 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_dinner(int nbr_philo, t_philo **philo, pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	while (i < nbr_philo)
	{
		free((*philo)[i].eating);
		i++;
	}
	free(*philo);
	free(*forks);
}

void	ft_free_data(t_data *data)
{
	free(data->m_lock);
	free(data->t_lock);
	free(data->rip);
	free(data->check_m_lock);
}
