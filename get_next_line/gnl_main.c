/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:00:44 by eorer             #+#    #+#             */
/*   Updated: 2023/03/26 03:08:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;
	char	*delimiter;

	delimiter = argv[1];
	str = get_next_line(0);
	while (strcmp(str, delimiter))
	{
		
	}
	printf("%s", str);
	return (0);
}
