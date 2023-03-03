/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:16:12 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/03 02:27:00 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_dinner(t_philo **philo, pthread_mutex_t **forks)
{
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
