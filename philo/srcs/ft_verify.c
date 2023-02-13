/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:56:49 by fmoreira          #+#    #+#             */
/*   Updated: 2023/02/13 22:11:14 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_verify(int argc, char **argv)
{
	int i;

	i = ft_isnum(argv, argc);
	if (i)
	{
		if (argc < 4)
			printf("too feel arguments\n");
		else if (argc > 5)
			printf("too many arguments\n");
		else if (i == 1)
			printf("invalid parameter\n");
		return (1);
	}
	return (0);	
}
