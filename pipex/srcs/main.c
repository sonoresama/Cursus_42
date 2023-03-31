/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:58:52 by eorer             #+#    #+#             */
/*   Updated: 2023/03/31 15:07:11 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	init_multi_pipes(&pipex, ac, av);
	nb_cmd = check_args(ac);
	dup2(pipex.infile, 0);
	while (i < nb_cmd - 1)
	{
		cmd(&pipex, av, env, i);
		i++;
	}
	waitpid(0, NULL, 0);
	dup2(pipex.outfile, 1);
	ft_exec(&pipex, av, env, nb_cmd - 1);
}
