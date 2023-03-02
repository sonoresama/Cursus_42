/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:16:45 by eorer             #+#    #+#             */
/*   Updated: 2023/03/01 14:53:18 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*join_three(char *s1, char *s2, char *s3)
{
	char	*str;
	char	*join;

	str = ft_strjoin(s1, s2);
	if (!str)
		return (NULL);
	join = ft_strjoin(str, s3);
	if (!join)
		return (NULL);
	free(str);
	return (join);
}

void	error_msg(int custom, char *str)
{
	if (custom)
		ft_printf("ERREUR : %s\n", str);
	else
		perror("ERREUR");
	exit(1);
}

void	print_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
