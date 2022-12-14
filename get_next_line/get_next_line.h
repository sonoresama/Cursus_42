/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:49:29 by eorer             #+#    #+#             */
/*   Updated: 2022/11/28 11:55:51 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
char	*split_left(char *str);
char	*split_right(char *str);
size_t	ft_strlen(char *str);

#endif
