/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:21:10 by emileorer         #+#    #+#             */
/*   Updated: 2022/11/23 13:50:50 by eorer            ###   ########.fr       */
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

	fd = open("texte.txt", O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}
