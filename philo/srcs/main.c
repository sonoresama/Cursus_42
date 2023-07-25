/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:56:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/25 18:15:48 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philos(t_philo *philos);

void	*ft_philo(void *arg)
{
	t_philo *philo;
	int	i = 0;

	philo = (t_philo *)arg;
	while (i++ < 10000)
	{
		if (ft_eating(philo))
			exit (0);
		ft_print(philo, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
		if (ft_print(philo, "is thinking"))
			exit(0);
	}
	return (NULL);
}

int	ft_join_threads(t_philo *philos)
{
	int	i;

	i = 0;
	while (i++ < philos->nb_philo)
	{
		if (pthread_join(philos->data->threads[i], NULL))
		{
			printf("Error creating thread\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo		*philos;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	philos = ft_initiate_philo(argv);
	if (!philos)
		return (1);
	print_philos(philos);
	if(ft_generate_threads(philos, philos->nb_philo))
		return (1);
	ft_join_threads(philos);
	//free_all(philos, threads);
	return (0);
}

void	print_philos(t_philo *philos)
{
	return;
	int	i;

	i = 0;
	while (philos && i++ < philos->nb_philo)
	{
		printf("Num philo : %i\n", philos->id);
		philos = philos->next;
	}
}
