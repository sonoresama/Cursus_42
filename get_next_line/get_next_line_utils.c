/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:38:41 by emileorer         #+#    #+#             */
/*   Updated: 2022/11/22 11:20:19 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && j < (size - i - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (start > ft_strlen(s) - 1)
		str = (char *)malloc(1);
	else if (len > ft_strlen(s))
		str = (char *)malloc(ft_strlen(s) + 1);
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

t_list	*add_new(char *buffer)
{
	t_list	*list;

	if (!buffer)
		return (NULL);
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->buffer = buffer;
	list->len = ft_strlen(buffer);
	list->next = NULL;
	return(list);
}

void	add_back(t_list **begin_list, t_list *new)
{
	t_list	*last;

	if(!new)
		return ;
	last = *begin_list;
	while (last && last->next)
		last = last->next;
	if (*begin_list)
		last->next = new;
	else
		*begin_list = new;
}
