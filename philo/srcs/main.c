/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:45:55 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/03 18:38:53 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (ft_verify(argc, argv))
		return (1);
	ft_init_data(argc, argv, &data);
	ft_init_dinner(&data, data.nbr_philo, &forks, &philo);
	ft_begin_dinner(philo);
	ft_free_dinner(&philo, &forks);
	ft_free_data(&data);
	return (0);
}
