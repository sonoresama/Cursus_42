/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:40:25 by eorer             #+#    #+#             */
/*   Updated: 2023/03/01 15:44:50 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	cmd_out(t_pipex *pipex, char **av, char **env)
{
	close(pipex->pipe[1]);
	pipex->outfile = open(av[4], O_CREAT | O_RDWR, 0666);
	if (pipex->outfile < 0)
		error_msg(0, NULL);
	pipex->out.argv = set_argv(av[3]);
	pipex->out.cmd = path_cmd(pipex->out.argv[0], env);
	if (pipex->out.cmd == NULL)
	{
		free_split(pipex->out.argv);
		error_msg(0, NULL);
	}
	dup2(pipex->pipe[0], 0);
	dup2(pipex->outfile, 1);
	execve(pipex->out.cmd, pipex->out.argv, env);
}
