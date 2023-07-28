/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:56:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/28 14:55:15 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philos(t_philo *philos);

int	ft_join_threads(t_philo *philos)
{
	int	i;
	int	error;

	i = 0;
	printf("\nJOIN\nEDEADLK : %i\nEINVAL : %i\nESRCH : %i\n", EDEADLK, EINVAL, ESRCH);
	while (i++ < philos->nb_philo)
	{
		printf("Waiting for thread n%i\n", i);
		error = pthread_join(philos->data->threads[i], NULL);
		if (error)
		{
			printf("Error creating thread : %i\n", error);
			return (1);
		}
		printf("Received thread n%i\n", i);
	}
	return (0);
}

int	ft_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("ERROR : Wrong number of arguments\n");
		return (1);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("ERROR : Negative numbers\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;

	if (ft_check(argc, argv))
		return (0);
	philo = ft_initiate_philo(argv);
	if (!philo)
		return (1);
	if(ft_generate_threads(philo))
		return (1);
//	while (philo->data->dead == 0)
//		;
	ft_join_threads(philo);
	//free_all(philos, threads);
	return (0);
}

void	print_philos(t_philo *philos)
{
	int	i;

	i = 0;
	return; 
	while (philos && i++ < philos->nb_philo)
	{
		printf("Num philo : %i\n", philos->id);
		printf("time to die : %i\n", philos->time_to_die);
		printf("time to sleep : %i\n", philos->time_to_sleep);
		printf("time to eat : %i\n", philos->time_to_eat);
		philos = philos->next;
	}
}
