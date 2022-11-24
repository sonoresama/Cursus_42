/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:54:16 by eorer             #+#    #+#             */
/*   Updated: 2022/11/24 19:01:12 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

static char	*get_buffer(int fd, char *right)
{
	char	*buffer;
	char	*str;
	int	bytes_rd;

	bytes_rd = 1;
	str = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (bytes_rd != 0 && !is_new_line(buffer))
	{
		bytes_rd = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (bytes_rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (right)
		{
			str = ft_strjoin(str, right);
			right = NULL;
		}
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*split_left(char *str)
{
	int	i;
	int	j;
	char	*left;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	left = (char *)malloc(sizeof(char) * (i + 2));
	if (!left)
		return (NULL);
	while (j <= i)
	{
		left[j] = str[j];
		j++;
	}
	left[j] = '\0';
	return (left);
}

static char	*split_right(char *str)
{
	int	i;
	int	j;
	char	*right;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	right = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!right)
		return (NULL);
	while (str[i + j])
	{
		right[j] = str[i + 1 + j];
		j++;
	}
	right[j] = '\0';
	return (right);
}

char	*get_next_line(int fd)
{
	static char	*right;
	char	*left;
	char	*next_line;

	next_line = get_buffer(fd, right);
	if (is_new_line(next_line))
	{
		left = split_left(next_line);
		right = split_right(next_line);
	}
	else
	{
		left = next_line;
		right = NULL;
	}
	free(next_line);
	return (left);
}

int	main()
{
	char	*str;
	int	fd;
	int	n;

	n = 1;
	fd = open("texte.txt", O_RDWR);
	str = get_next_line(fd);
	printf("%i./\n", n);
	printf("%s\n", str);
	while (str != NULL && n < 1)
	{
		n++;
		printf("%i./\n", n);
		str = get_next_line(fd);
		printf("%s", str);
	}
	free(str);
	return (0);
}
