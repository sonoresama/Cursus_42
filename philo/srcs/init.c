/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:22:33 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/26 14:42:28 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*ft_lstnew(int id, char **args, t_data *data)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id + 1;
	new->nb_philo = ft_atoi(args[1]);
	new->time_to_die = ft_atoi(args[2]);
	new->time_to_eat = ft_atoi(args[3]);
	new->time_to_sleep = ft_atoi(args[4]);
	new->nb_eat = -1;
	new->last_meal = 0;
	new->data = data;
	new->check = 0;
	pthread_mutex_init(&new->fork, NULL);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_philo *ft_initiate_philo(char **argv)
{
	t_philo		*begin;
	t_data		*data;
	int		i;

	i = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_bzero(data, sizeof(t_data));
	begin = ft_lstnew(i, argv, data);
	printf("begin -> nb_philo = %d\n", begin->nb_philo);
	while (++i <= ft_atoi(argv[1]))
		ft_lstadd_back(&begin, ft_lstnew(i, argv, data));
	begin->prev = ft_lstlast(begin);
	begin->prev->next = begin;
	data->threads = malloc(sizeof(pthread_t) * begin->nb_philo);
	if (!data->threads)
	{
		printf("Error allocating memory\n");
		return (NULL);
	}
	pthread_mutex_init(&data->lock, NULL);
	return (begin);
}
