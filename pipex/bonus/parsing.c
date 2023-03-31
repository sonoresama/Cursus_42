/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:48:36 by eorer             #+#    #+#             */
/*   Updated: 2023/03/31 14:50:33 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	**parsing_path(char **env)
{
	char	*path;
	char	**split;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp("PATH", env[i], 4))
		i++;
	if (env[i])
		path = ft_strdup(env[i]);
	else
		return (NULL);
	split = ft_split(path, ":");
	if (!split)
		return (NULL);
	split[0] = split[0] + ft_strlen("PATH=");
	free(path);
	return (split);
}

char	*path_cmd(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*path_cmd;

	path = parsing_path(env);
	if (!access(cmd, F_OK | X_OK))
		return (cmd);
	if (!path)
		error_msg(1, "Split");
	i = 0;
	while (path[i])
	{
		path_cmd = join_three(path[i], "/", cmd);
		if (!path_cmd)
			error_msg(1, "Join");
		if (!access(path_cmd, F_OK | X_OK))
		{
			path[0] = path[0] - ft_strlen("PATH=");
			free_split(path);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	path[0] = path[0] - ft_strlen("PATH=");
	free_split(path);
	return (NULL);
}
