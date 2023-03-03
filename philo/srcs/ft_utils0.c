/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:24:04 by fmoreira          #+#    #+#             */
/*   Updated: 2023/02/28 01:23:43 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnum(char **str, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc < 5 || argc > 6)
		return (2);
	while ((int)str[j][i] >= 48 && (int)str[j][i] <= 57)
	{
		i++;
		if (!str[j][i] && ++j < argc)
			i = 0;
		if (j >= argc && --j)
			break ;
		if ((int)str[j][i] < 48 || (int)str[j][i] > 57)
			return (1);
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	signal;

	i = 0;
	result = 0;
	signal = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10) + str[i] - '0' >= INT_MAX)
			return (INT_MAX);
		if ((result * 10) + str[i] - '0' <= INT_MIN)
			return (INT_MIN);
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (signal * result);
}
