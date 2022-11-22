/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:06:21 by emileorer         #+#    #+#             */
/*   Updated: 2022/11/22 12:32:33 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	print_list(t_list *begin_list)
{
	t_list	*tmp;

	if (!begin_list)
		return ;
	tmp = begin_list;
	while (tmp)
	{
		printf("--> %s\n", tmp->buffer);
		tmp = tmp->next;
	}
}

static int	get_chained_list(int fd, t_list **begin_list)
{
	char	*buffer;
	char	*line;
	size_t	i;

	i = 0;
	if (BUFFER_SIZE == 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	read(fd, buffer, BUFFER_SIZE);
	if (!buffer[0])
		return (0);
	buffer[BUFFER_SIZE] = '\0';
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + (buffer[i] == '\n'));
	add_back(begin_list, add_new(line));
	if (line[ft_strlen(line) - 1] != '\n')
		return (-1);
	else
		return (1);
}

char	*get_next_line(int fd)
{
	t_list	*list;
	char	*str;
	size_t	size;
	int		i;

	i = -1;
	list = NULL;
	while (i == -1)
	{
		i = get_chained_list(fd, &list);
		if (i != 0)
			size = size + list->len;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str || !size)
		return (NULL);
	str = list->buffer;
	while (list->next)
	{
		list = list->next;
		ft_strlcat(str, list->buffer, INT_MAX);
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
