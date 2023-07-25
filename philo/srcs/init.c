/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:22:33 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/25 18:14:32 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*ft_lstnew(int id, char **args, t_data *data)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->nb_philo = ft_atoi(args[1]);
	new->time_to_die = ft_atoi(args[2]);
	new->time_to_eat = ft_atoi(args[3]);
	new->time_to_sleep = ft_atoi(args[4]);
	new->nb_eat = -1;
	new->last_meal = 0;
	new->data = data;
	pthread_mutex_init(&new->fork, NULL);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_philo *ft_initiate_philo(char **argv)
{
	t_philo	*begin;
	t_data	*data;
	int		i;

	i = 1;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_bzero(data, sizeof(t_data));
	pthread_mutex_init(&data->dead, NULL);
	begin = ft_lstnew(i, argv, data);
	while (++i <= ft_atoi(argv[1]))
		ft_lstadd_back(&begin, ft_lstnew(i, argv, data));
	begin->prev = ft_lstlast(begin);
	begin->prev->next = begin;
	return (begin);
}

int	ft_generate_threads(t_philo *philo, int nb_philo)
{
	int		i;
	pthread_t	*threads;
	t_philo		*tmp;

	i = 0;
	threads = malloc(sizeof(pthread_t) * nb_philo);
	if (!threads)
	{
		printf("Error allocating memory\n");
		return (1);
	}
	philo->data->start = ft_get_time();
	philo->data->threads = threads;
	tmp = philo;
	while (i < nb_philo)
	{
		philo->last_meal = philo->data->start;
		if (pthread_create(&threads[i], NULL, &ft_philo, philo) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		philo = philo->next->next;
		i += 2;
	}
	i = 1;
	tmp = tmp->next;
	while (i < nb_philo)
	{
		philo->last_meal = philo->data->start;
		if (pthread_create(&threads[i], NULL, &ft_philo, philo) != 0)
		{
			printf("Error creating thread\n");
			return (1);
		}
		philo = philo->next;
		i += 2;
	}
	return (0);
}
