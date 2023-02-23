/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:04:46 by eorer             #+#    #+#             */
/*   Updated: 2022/11/16 15:25:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;

	if (!del)
		return ;
	while (lst && *lst)
	{
		list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = list;
	}
}

void	ft_printf_list(t_list *begin_list)
{
	t_list	*tmp;

	tmp = begin_list;
	while (tmp)
	{
		ft_putstr_fd(tmp->content, 1);
		tmp = tmp->next;
	}
}

/*int	main(void)
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew("Hello "));
	ft_lstadd_back(&list, ft_lstnew("Tito "));
	ft_lstadd_back(&list, ft_lstnew("tu "));
	ft_lstadd_back(&list, ft_lstnew("vas "));
	ft_lstadd_back(&list, ft_lstnew("bien "));
	ft_lstadd_back(&list, ft_lstnew("?"));
	ft_printf_list(list);
	tmp = list;
	while (tmp && strcmp((char *)tmp->content, "tu"))
		tmp = tmp->next;
	printf("\n--> %p", tmp->content);
	ft_lstclear(&tmp, free);
	ft_putstr_fd("\n\n\n", 1);
	ft_printf_list(list);
	return (0);
}*/
