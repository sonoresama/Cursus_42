/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:40:51 by eorer             #+#    #+#             */
/*   Updated: 2022/11/15 17:50:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libftprintf.h"

typedef void	(*fn_type)(void);

/*void	ft_printf_functions(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar_fd((char)*arg, 1);
	if (c == 's')
		ft_putstr_fd((char *)*arg, 1);
	//if (c == 'p')
	//	 ();
	if (c == 'd' || c == 'i')
		ft_putnbr_fd((int)*arg, 1);
	if (c == 'u')
		 (&ft_unsigned_putnbr_fd);
	if (c == 'x')
		 (&ft_puthexamin_fd);
	if (c == 'X')
		 (&ft_puthexamaj_fd);
}*/
fn_type	ft_printf_functions(char c, va_list arg)
{
	if (c == 'c')
		return (&ft_putchar_fd);
	/*if (c == 's')
		ft_putstr_fd((char *)*arg, 1);
	//if (c == 'p')
	//	 ();
	if (c == 'd' || c == 'i')
		ft_putnbr_fd((int)*arg, 1);
	if (c == 'u')
		 (&ft_unsigned_putnbr_fd);
	if (c == 'x')
		 (&ft_puthexamin_fd);
	if (c == 'X')
		 (&ft_puthexamaj_fd);*/
	else
		return (NULL);
}
