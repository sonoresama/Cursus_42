/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:54:16 by eorer             #+#    #+#             */
/*   Updated: 2022/11/30 12:04:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static int	is_new_line(char *buffer)
{
	if (!buffer)
		return (0);
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

static char	*return_str(char *buffer, int bytes_rd, char *right, char *str)
{
	if (right)
	{
		str = ft_strjoin(str, right);
		right = NULL;
	}
	if (bytes_rd == 0)
		str = ft_strjoin(str, NULL);
	else
		str = ft_strjoin(str, buffer);
	return (str);
}

static char	*get_buffer(int fd, char *right)
{
	char	*buffer;
	char	*str;
	int		bytes_rd;

	bytes_rd = 1;
	str = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (bytes_rd > 0 && !is_new_line(buffer))
	{
		bytes_rd = read(fd, buffer, BUFFER_SIZE);
		if (bytes_rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_rd] = '\0';
		str = return_str(buffer, bytes_rd, right, str);
		right = NULL;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*right;
	char		*left;
	char		*next_line;

	next_line = get_buffer(fd, right);
	if (right)
		free(right);
	if (is_new_line(next_line))
	{
		left = split_left(next_line);
		right = split_right(next_line);
		free(next_line);
	}
	else
	{
		left = next_line;
		right = NULL;
	}
	return (left);
}
/*int	main()
{
	int	fd;
	int	n;
	char	*str;

	n = 1;
	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDWR);
	while (1)
	{
		printf("--> %i. \n", n);
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s", str);
		n++;
		free(str);
	}
	return (0);
}*/
