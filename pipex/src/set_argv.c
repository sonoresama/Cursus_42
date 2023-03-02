/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:53:43 by eorer             #+#    #+#             */
/*   Updated: 2023/03/01 15:47:00 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*int	size_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}*/

char	**set_argv(char *param)
{	
	char	**split;

	split = ft_split(param, " ");
	if (!split)
		error_msg(1, "Split Arguments");
	return (split);
}
