/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:34:25 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/22 16:30:17 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int id, char **args)
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
	pthread_mutex_init(&new->fork, NULL);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	if (!new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		new->prev = last;
		last->next = new;
	}
	else
		*lst = new;
}

void	free_list(t_philo *list)
{
	t_philo	*tmp;

	while (list)
	{
		tmp = list->next;
		pthread_mutex_destroy(&list->fork);
		free(list);
		list = tmp;
	}
}
