/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:26:17 by eorer             #+#    #+#             */
/*   Updated: 2022/11/24 18:29:37 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

size_t	where_is_ln(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

char	**ft_parsing(char *tampon, char *buffer)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 3);
	if (!tab)
		return (NULL);
	tab[0] = (char *)malloc(sizeof(char) * (where_is_ln(buffer) + ft_strlen(tampon) + 1));
	if (!tab[0])
		return (NULL);
	if (ft_strlen(buffer) - where_is_ln(buffer))
	{
		tab[1] = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - where_is_ln(buffer) + 1));
		if (!tab[1])
			return (NULL);
	}
	else
		tab[1] = NULL;
	if (tampon)
	{
		ft_strlcpy(tab[0], tampon, ft_strlen(tampon));
		ft_strcat(tab[0], buffer);
	}
	else
		ft_strlcpy(tab[0], buffer, where_is_ln(buffer) + 2);
	ft_strlcpy(tab[1], &buffer[where_is_ln(buffer) + 2], ft_strlen(buffer));
	tab[2] = NULL;
	return (tab);
}

char	*get_next_line(int fd)
{
	char		**tab;
	char		*str;
	char		*str_free;
	char		*buffer;
	static char	*tampon;
	int	bytes_rd;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_rd = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_rd] = '\0';
	tab = ft_parsing(tampon, buffer);
	str = ft_strdup(tab[0]);
	tampon = ft_strdup(tab[1]);
	while (str[ft_strlen(str) - 1] != '\n' && bytes_rd != 0)
	{
		free_tab(tab);
		read(fd, buffer, BUFFER_SIZE);
		tab = ft_parsing(tampon, buffer);
		str_free = str;
		str = ft_strjoin(str, tab[0]);
		tampon = ft_strdup(tab[1]);
		free(str_free);
	}
	free_tab(tab);
	free(buffer);
	printf("\n   TAMPON : %s\n", tampon);
	str[ft_strlen(str)] = '\0';
	return (str);
}

int	main(void)
{
	int	fd;
	char	*str;
	int	n;

	n= 0;
	fd = open("texte.txt", O_RDWR);
	while (n < 5)
	{
		str = get_next_line(fd);
		printf("%s", str);
		n++;
	}
	free(str);
	return (0);
}
