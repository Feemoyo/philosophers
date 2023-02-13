/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:45:55 by fmoreira          #+#    #+#             */
/*   Updated: 2023/02/13 22:28:59 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv) //argv[1] = num_philo
{
	t_plist	*table;
	//pthread_t	t1;

	if (ft_verify(argc, argv))
		return (1);
	table = ft_init_plist(argv[1]);
	ft_init_philo(table);
	//printf("argv[0]: %s\nargv[1]: %s\nnum_philo: %d\n", argv[0], argv[1], table.size);
	//pthread_create(&t1, NULL, &pprint_thread, NULL);
	//pthread_join(t1, NULL);
	return (0);
}

void	*pprint_thread()
{
	printf("apenas o join executa a função\n");
	return (0);
}