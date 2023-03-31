/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:58:52 by eorer             #+#    #+#             */
/*   Updated: 2023/03/31 14:53:30 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init_here_doc(t_pipex *pipex, int ac, char **av)
{
	pipex->infile = open("test", O_CREAT | O_RDWR, 0666);
	pipex->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0666);
	pipex->here_doc = 1;
	if (pipex->infile == -1 || pipex->outfile == -1)
		error_msg(0, NULL);
	ft_here_doc(av, pipex);
	pipex->infile = open("test", O_CREAT | O_RDWR, 0666);
}

void	init_multi_pipes(t_pipex *pipex, int ac, char **av)
{
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[ac - 1], O_CREAT | O_RDWR, 0666);
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		nb_cmd;
	t_pipex	pipex;

	i = 0;
	ft_bzero(&pipex, sizeof(t_pipex));
	if (!ft_strncmp(av[1], "here_doc", ft_strlen("here_doc")))
		init_here_doc(&pipex, ac, av);
	else
		init_multi_pipes(&pipex, ac, av);
	nb_cmd = check_args(ac) - pipex.here_doc;
	dup2(pipex.infile, 0);
	while (i < nb_cmd - 1)
	{
		cmd_bonus(&pipex, av, env, i);
		i++;
	}
	waitpid(0, NULL, 0);
	if (pipex.here_doc)
		unlink("test");
	dup2(pipex.outfile, 1);
	ft_exec(&pipex, av, env, nb_cmd - 1);
}
