/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:17:38 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/03 02:25:13 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_table_utils(t_philo *philo)
{
	printf("%ld %d has taken a fork\n%ld %d has taken a fork\n",
		ft_current_time(philo->data->first_meal), philo->index,
		ft_current_time(philo->data->first_meal), philo->index);
}
