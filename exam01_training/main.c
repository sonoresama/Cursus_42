/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:49:16 by eorer             #+#    #+#             */
/*   Updated: 2022/12/08 15:15:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
	char		*content;
	struct s_list	*next;
}	t_list;

t_list	*new_maillon(char *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	add_front(t_list **begin_list, t_list *maillon)
{
	if(!maillon)
		return ;
	maillon->next = *begin_list;
	*begin_list = maillon;
}

void	printf_list(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	while(tmp)
	{
		printf("--> %s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	free_lst(t_list **begin_list)
{
	t_list	*tmp;

	while(tmp)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = tmp;
	}
	free(*begin_list);
}

int	main(int argc, char **argv)
{
	t_list	*begin_list;
	int	i;

	i = 1;
	begin_list = NULL;
	while (i < argc)
	{
		add_front(&begin_list, new_maillon(argv[i]));
		i++;
	}
	printf_list(&begin_list);
	free_lst(&begin_list);
	return (0);
}
