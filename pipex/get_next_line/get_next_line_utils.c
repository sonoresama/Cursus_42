/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:27:16 by eorer             #+#    #+#             */
/*   Updated: 2022/12/24 15:02:53 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*split_left(char *str)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !*str)
		return (NULL);
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

char	*split_right(char *str)
{
	char	*right;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i + 1] == '\0')
		return (NULL);
	right = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
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

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;	
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s1)
		free(s1);
	str[i + j] = '\0';
	return (str);
}

/*char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (NULL);
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	dest [i] = '\0';
	return (dest);
}*/
