/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:32:41 by fmoreira          #+#    #+#             */
/*   Updated: 2023/02/13 23:44:26 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_plist	*table)
{
	int		i;
	t_pnode	*aux;

	i = 0;
	aux = &table->top_node;
	while (i++ != table->size)
	{
		if (pthread_create(&aux->philo, NULL, &pprint_thread, NULL))
			printf("deu ruim mane :C\n");
		aux->next = ft_init_node(aux);
		aux = aux->next;
		printf("Alo\n");
	}
	table->top_node.previus = aux;
	i = 0;
	aux = &table->top_node;
	while (i++ != table->size)
	{
		printf("SIM %d: %p ", i, aux);
		//pthread_join(aux->philo, NULL);
		aux = aux->previus;
	}
	return (0);
}

t_plist	*ft_init_plist(char	*argv1)
{
	t_plist	*philo_list;

	philo_list = (t_plist *)malloc(sizeof(t_plist));
	philo_list->size = ft_atoi(argv1);
	return (philo_list);
}

t_pnode	*ft_init_node(t_pnode	*previus)
{
	t_pnode	*node;

	node = malloc(sizeof(t_pnode));
	//node->d = 
//	node->fork = 0;
	node->next = NULL;
	node->previus = previus;
	return (node);
}