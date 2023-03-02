/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:38:14 by eorer             #+#    #+#             */
/*   Updated: 2023/03/01 15:53:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	cmd_in(t_pipex *pipex, char **av, char **env)
{
	close(pipex->pipe[0]);
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		error_msg(0, NULL);
	pipex->in.argv = set_argv(av[2]);
	pipex->in.cmd = path_cmd(pipex->in.argv[0], env);
	if (pipex->in.cmd == NULL)
	{
		free_split(pipex->in.argv);
		error_msg(0, NULL);
	}
	dup2(pipex->pipe[1], 1);
	dup2(pipex->infile, 0);
	execve(pipex->in.cmd, pipex->in.argv, env);
}
