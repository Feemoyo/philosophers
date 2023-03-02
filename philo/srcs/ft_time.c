/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:46:52 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/01 19:25:49 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_set_timer(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_ms_sleep(int time_in_ms)
{
	long	start;

	start = ft_set_timer();
	while ((ft_set_timer() - start) < (long)time_in_ms)
		usleep(10);
}

long	ft_current_time(long start)
{
	return (ft_set_timer() - start);
}
