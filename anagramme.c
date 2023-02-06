/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anagramme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:03:48 by emileorer         #+#    #+#             */
/*   Updated: 2023/02/06 09:26:43 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	is_ASCII(int c)
{
	if (c > 0 && c < 128)
		return 1;
	return 0;
}

int	recursive(int letter, char *str, char *argv) 
{
	int	i = 0;
	if (letter == (int)strlen(argv)) // letter représente l'index de la lettre sur laquelle on travaille i.e. index dans argv
	{
		printf("%s\n", str);
		return 0;
	}
	while (i < (int)strlen(argv)) //i représente l'index ou l'on souhaite placer la lettre en question i.e. index dans str
	{
		if (!is_ASCII(str[i]))
		{
			str[i] = argv[letter];
			recursive(letter + 1, str, argv);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char *str;

	(void)argc;
	str = (char *)calloc(strlen(argv[1]), sizeof(char));
	recursive(0, str, argv[1]);
	return 0;
}
