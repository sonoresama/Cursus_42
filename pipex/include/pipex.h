/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:23:54 by eorer             #+#    #+#             */
/*   Updated: 2023/03/01 14:43:52 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmd{
	char	*cmd;
	char	**argv;
}	t_cmd;

typedef struct s_pipex{
	int		infile;
	int		outfile;
	int		pipe[2];
	t_cmd	in;
	t_cmd	out;
}	t_pipex;

void	print_split(char **tab);
void	free_split(char **split);
void	error_msg(int custom, char *str);
void	cmd_in(t_pipex *pipex, char **av, char **env);
void	cmd_out(t_pipex *pipex, char **av, char **env);
char	*path_cmd(char *cmd, char **env);
char	*join_three(char *s1, char *s2, char *s3);
char	**set_argv(char *param);
int		check_args(int argc, char **argv);

#endif
