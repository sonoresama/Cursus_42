/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:23:54 by eorer             #+#    #+#             */
/*   Updated: 2023/03/27 17:58:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/ft_printf.h"
# include "get_next_line.h"
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
	int		here_doc;
	t_cmd	cmd;
}	t_pipex;

void	print_split(char **tab);
void	free_split(char **split);
void	error_msg(int custom, char *str);
void	ft_here_doc(char **argv, t_pipex *pipex);
char	*path_cmd(char *cmd, char **env);
char	*join_three(char *s1, char *s2, char *s3);
char	**set_argv(char *param);
void	ft_exec(t_pipex *pipex, char **av, char **env, int num);
void	cmd_bonus(t_pipex *pipex, char **av, char **env, int num);
int		check_args(int argc);

#endif
