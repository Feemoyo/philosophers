/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:31:59 by fmoreira          #+#    #+#             */
/*   Updated: 2023/02/13 23:41:36 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>

typedef struct	s_pnode
{
	pthread_t				philo;
	pthread_mutex_t			fork;
	int						d
	struct s_pnode			*next;
	struct s_pnode			*previus;
}	t_pnode;

typedef struct s_plist
{
	int				size;
	struct s_pnode	top_node;
	unsigned char	lock:1;
}	t_plist;

int		ft_verify(int argc, char **argv);
int		ft_isnum(char **str, int argc);
int		ft_atoi(const char *str);

t_plist	*ft_init_plist(char	*argv1);
int	ft_init_philo(t_plist *table);
t_pnode	*ft_init_node(t_pnode	*previus);


void	*pprint_thread();



#endif