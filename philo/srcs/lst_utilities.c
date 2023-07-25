/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:34:25 by emileorer         #+#    #+#             */
/*   Updated: 2023/07/25 16:53:58 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
