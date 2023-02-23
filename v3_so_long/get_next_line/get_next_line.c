/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:54:16 by eorer             #+#    #+#             */
/*   Updated: 2022/12/24 15:02:40 by eorer            ###   ########.fr       */
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
		str = gnl_ft_strjoin(str, right);
		right = NULL;
	}
	if (bytes_rd == 0)
		str = gnl_ft_strjoin(str, NULL);
	else
		str = gnl_ft_strjoin(str, buffer);
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
	while (bytes_rd > 0 && !is_new_line(str))
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
	char		*line;

	line = get_buffer(fd, right);
	if (right)
		free(right);
	if (is_new_line(line))
	{
		left = split_left(line);
		right = split_right(line);
		free(line);
	}
	else
	{
		left = line;
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
	fd = open("get_next_line.h", O_RDWR);
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
