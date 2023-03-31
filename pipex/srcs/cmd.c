/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:45:42 by eorer             #+#    #+#             */
/*   Updated: 2023/03/31 15:07:56 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_exec(t_pipex *pipex, char **av, char **env, int num)
{
	pipex->cmd.argv = set_argv(av[num + 2]);
	pipex->cmd.cmd = path_cmd(pipex->cmd.argv[0], env);
	if (pipex->cmd.cmd == NULL)
	{
		free_split(pipex->cmd.argv);
		error_msg(1, "command not found");
	}
	if (execve(pipex->cmd.cmd, pipex->cmd.argv + 1, env) == -1)
	{
		free_split(pipex->cmd.argv);
		free(pipex->cmd.cmd);
		error_msg(0, NULL);
	}
}

void	cmd(t_pipex *pipex, char **av, char **env, int num)
{
	pid_t	pid;
	int		ft_pipe[2];

	if (pipe(ft_pipe) == -1)
		error_msg(0, NULL);
	pid = fork();
	if (pid == (pid_t)-1)
		error_msg(0, NULL);
	if (pid != 0)
	{
		close(ft_pipe[1]);
		dup2(ft_pipe[0], 0);
		waitpid(0, NULL, 0);
	}
	else
	{
		if (pipex->infile < 0)
		{
			pipex->infile = 0;
			error_msg(1, "no such file or directory");
		}
		close(ft_pipe[0]);
		dup2(ft_pipe[1], 1);
		ft_exec(pipex, av, env, num);
	}
}
