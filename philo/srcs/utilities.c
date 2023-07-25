/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:13:15 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/25 18:00:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_all(t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	printf("nb de philo au moment de free : %i\n", philo->nb_philo);
	while(i < philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->fork);
		philo = philo->next;
		if (philo->prev)
			free(philo->prev);
		i++;
	}
	free(threads);
}

long	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	resultat;

	resultat = 0;
	neg = 1;
	while ((*nptr >= 8 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		neg = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr) && *nptr)
	{
		resultat = resultat * 10 + *nptr - '0';
		nptr++;
	}
	return (resultat * neg);
}

void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
}
