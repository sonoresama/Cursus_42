/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:56:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/31 12:17:27 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_join_threads(t_philo *philos)
{
	int	i;
	int	error;

	i = 0;
	while (i++ < philos->nb_philo)
	{
		error = pthread_join(philos->data->threads[i], NULL);
		if (error)
		{
			printf("Error joining thread : %i\n", error);
			return (1);
		}
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
	if (ft_check(argc, argv))
		return (0);
	philo = ft_initiate_philo(argv);
	if (!philo)
		return (1);
	if (philo->nb_philo == 1)
		return (one_philo(philo));
else if (ft_generate_threads(philo))
		return (1);
	while (philo->data->dead == 0)
		;
	//ft_join_threads(philo);
	ft_exit(philo);
	return (0);
}
