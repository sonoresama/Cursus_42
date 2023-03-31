/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:53:43 by eorer             #+#    #+#             */
/*   Updated: 2023/03/31 15:01:17 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**set_argv(char *param)
{	
	char	**split;

	split = ft_split(param, " ");
	if (!split)
		error_msg(1, "Split Arguments");
	return (split);
}
