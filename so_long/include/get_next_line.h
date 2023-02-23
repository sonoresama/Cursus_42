/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:49:29 by eorer             #+#    #+#             */
/*   Updated: 2022/12/24 15:04:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*gnl_ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*split_left(char *str);
char	*split_right(char *str);
size_t	ft_strlen(const char *str);

#endif
