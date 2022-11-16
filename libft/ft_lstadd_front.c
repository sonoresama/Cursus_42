/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:29:19 by eorer             #+#    #+#             */
/*   Updated: 2022/11/16 15:23:54 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*ptr_lst;

	if (*lst)
	{
		ptr_lst = *lst;
		new->next = ptr_lst;
	}
	*lst = new;
}

/*int	main(void)
{
	t_list	*list;
	t_list	*new;
	t_list	*new2;

	list = NULL;
	new = ft_lstnew("Tito");
	ft_lstadd_front(&list, new);
	printf("--> %s\n", (char *)list->content);
	printf("--> %p\n", (char *)list->next);
	
	new2 = ft_lstnew("Hello");
	ft_lstadd_front(&list, new2);
	printf("--> %s\n", (char *)list->content);
	printf("--> %s\n", (char *)list->next->content);
	printf("--> %p\n", (char *)list->next->next);
	free(new);
	free(new2);
	return (0);
}*/
