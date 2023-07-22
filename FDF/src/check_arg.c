/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:45:11 by eorer             #+#    #+#             */
/*   Updated: 2023/03/30 15:44:56 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	comp_fdf(char *str, size_t len)
{
	char	*fdf;
	int		i;

	i = 0;
	fdf = ".fdf";
	while (str[i + len - 4])
	{
		if (str[i + len - 4] != fdf[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_arg(int argc, char *str)
{
	size_t	len;
	int		fd;

	if (argc != 2)
		return (1);
	len = ft_strlen(str);
	if (comp_fdf(str, len))
		return (1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		perror("File type");
		return (1);
	}
	close(fd);
	return (0);
}
