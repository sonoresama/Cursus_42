/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:45:42 by eorer             #+#    #+#             */
/*   Updated: 2023/03/31 17:08:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_exec(t_pipex *pipex, char **av, char **env, int num)
{
	pipex->cmd.argv = set_argv(av[num + 2 + pipex->here_doc]);
	pipex->cmd.cmd = path_cmd(pipex->cmd.argv[0], env);
	if (pipex->cmd.cmd == NULL)
	{
		free_split(pipex->cmd.argv);
		error_msg(1, "command not found");
	}
//	ft_putstr_fd("CMD : ", 2);
//	ft_putstr_fd(pipex->cmd.cmd, 2);
//	ft_putstr_fd("\n", 2);
//	ft_putstr_fd("Param : ", 2);
//	ft_putstr_fd(pipex->cmd.argv[1], 2);
//	ft_putstr_fd("\n", 2);
/*	if (!ft_strncmp(pipex->cmd.argv[0], "sleep", ft_strlen("sleep")))
		execve(pipex->cmd.cmd, ft_atoi(pipex->cmd.argv[1]), env);*/
	if (!ft_strncmp(pipex->cmd.argv[0], "cat", 3))
		close(pipex->infile);
	if (execve(pipex->cmd.cmd, pipex->cmd.argv, env) == -1)
	{
		free_split(pipex->cmd.argv);
		free(pipex->cmd.cmd);
		error_msg(0, NULL);
	}
}

void	ft_here_doc(char **argv, t_pipex *pipex)
{
	char	*str;
	char	*delimiter;

	ft_putstr_fd("pipe heredoc> ", 1);
	str = get_next_line(0);
	if (!str)
		error_msg(1, "GNL 1");
	delimiter = ft_strdup(argv[2]);
	while (ft_strncmp(str, delimiter, ft_strlen(delimiter)))
	{
		ft_putstr_fd(str, pipex->infile);
		ft_putstr_fd("pipe heredoc> ", 1);
		str = get_next_line(0);
		if (!str)
			error_msg(1, "GNL\n");
	}
	close(pipex->infile);
	free(str);
	free(delimiter);
}

void	cmd_bonus(t_pipex *pipex, char **av, char **env, int num)
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
		pipex->infile = 0;
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

/*int	main(int argc, char **argv)
{
	char	*str;
	char	*delimiter;
	t_list	*begin;
	t_list	*move;

	if (argc != 2)
		return (1);
	delimiter = argv[1];
	begin = NULL;
	ft_putstr_fd("here_doc >> ", 1);
	str = get_next_line(0);
	ft_putstr_fd(str, 1);
	if (!str)
	{
		ft_printf("ERREUR GNL\n");
		return (1);
	}
	while (ft_strncmp(str, delimiter, ft_strlen(delimiter)))
	{
		ft_lstadd_back(&begin, ft_lstnew(str));
		ft_putstr_fd("here_doc >> ", 1);
		str = get_next_line(0);
		ft_putstr_fd(str, 1);
		if (!str)
		{
			ft_lstclear(&begin, &free);
			ft_printf("ERREUR GNL\n");
			return (1);
		}
	}
	move = begin;
	while (move)
	{
		ft_printf("%s", move->content);
		move = move->next;
	}
	ft_lstclear(&begin, &free);
	free(str);
	return (0);
}*/
