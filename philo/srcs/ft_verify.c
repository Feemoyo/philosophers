/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:56:49 by fmoreira          #+#    #+#             */
/*   Updated: 2023/03/04 16:21:06 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_verify(int argc, char **argv)
{
	int	i;

	i = ft_isnum(argv, argc);
	if (i)
	{
		if (argc < 5)
			printf("Error: too feel arguments\n");
		else if (argc > 6)
			printf("Error: too many arguments\n");
		else if (i == 1)
			printf("Error: only integer values are allowed\n");
		return (1);
	}
	if (ft_atoi(argc[1] < 1))
	{
		printf("Error: Please do not try to break this code! :D")
		return (1);
	}
	return (0);
}
