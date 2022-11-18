/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:03:21 by eorer             #+#    #+#             */
/*   Updated: 2022/11/16 15:20:21 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;
	void	*new_content;

	tmp = lst;
	new_list = NULL;
	while (tmp)
	{
		new_content = f(tmp->content);
		ft_lstadd_back(&new_list, ft_lstnew(new_content));
		if (!new_list)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new_list);
}
