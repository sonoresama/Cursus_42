/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:21:10 by emileorer         #+#    #+#             */
/*   Updated: 2022/11/22 12:33:27 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void    print_list(t_list *begin_list);

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("./gnlTester/files/nl", O_RDWR);
	str = get_next_line(fd);
	printf("%s\n", str);
	return (0);
}
