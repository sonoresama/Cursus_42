/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:22:33 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/28 17:49:03 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*ft_lstnew(int id, char **argv, t_data *data)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id + 1;
	new->nb_philo = ft_atoi(argv[1]);
	new->time_to_die = ft_atoi(argv[2]);
	new->time_to_eat = ft_atoi(argv[3]);
	new->time_to_sleep = ft_atoi(argv[4]);
	if (data->max_meal)
		new->nb_eat = 0;
	else
		new->nb_eat = -1;
	new->last_meal = 0;
	new->data = data;
	pthread_mutex_init(&new->fork, NULL);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_data	*ft_init_data(char	**argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error allcoating memory : data\n");
		return (NULL);
	}
	ft_bzero(data, sizeof(t_data));
	data->threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!data->threads)
	{
		printf("Error allocating memory\n");
		return (NULL);
	}
	data->dead = 0;
	data->finished = 0;
	if (argv[5])
		data->max_meal = ft_atoi(argv[5]);
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
	return (data);
}

t_philo	*ft_initiate_philo(char **argv)
{
	t_philo		*begin;
	t_data		*data;
	int			nb_philo;
	int			i;

	i = 0;
	data = ft_init_data(argv);
	begin = ft_lstnew(i, argv, data);
	nb_philo = ft_atoi(argv[1]);
	while (++i < nb_philo)
		ft_lstadd_back(&begin, ft_lstnew(i, argv, data));
	begin->prev = ft_lstlast(begin);
	begin->prev->next = begin;
	return (begin);
}
