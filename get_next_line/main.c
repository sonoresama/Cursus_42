/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:21:10 by emileorer         #+#    #+#             */
/*   Updated: 2022/11/22 16:09:59 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

void    print_list(t_list *begin_list);

int	main(void)
{
	int	fd;
	char	*str;
	char	*dup;

	fd = open("texte.txt", O_RDWR);
	str = get_next_line(fd);
	dup = strdup(str);
	printf("%s\n", dup);
	return (0);
}
