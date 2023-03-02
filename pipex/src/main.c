/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:23:04 by eorer             #+#    #+#             */
/*   Updated: 2023/03/01 15:50:16 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/*void	free_all(t_pipex *pipex)
{
	free(pipex->in.cmd);
	free(pipex->out.cmd);
	free_split(pipex->in.argv);
	free_split(pipex->out.argv);
}*/

void	close_all(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

int	main(int argc, char **av, char **env)
{
	t_pipex	pipex;
	pid_t	pid_a;
	pid_t	pid_b;

	ft_bzero(&pipex, sizeof(pipex));
	check_args(argc, av);
	if (pipe(pipex.pipe) == -1)
		error_msg(0, NULL);
	pid_a = fork();
	if (pid_a == (pid_t)-1)
		error_msg(0, NULL);
	else if (pid_a == 0)
		cmd_in(&pipex, av, env);
	pid_b = fork();
	if (pid_b == (pid_t)-1)
		error_msg(0, NULL);
	else if (pid_b == 0)
		cmd_out(&pipex, av, env);
	close_all(&pipex);
	waitpid(pid_a, NULL, 0);
	waitpid(pid_b, NULL, 0);
	return (0);
}
