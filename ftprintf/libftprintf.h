/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:51 by eorer             #+#    #+#             */
/*   Updated: 2022/11/17 17:10:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

char    *ft_hexa(int nbr, char *base);
void	ft_unsigned_putnbr_fd(unsigned int nbr, int fd);
void	ft_format(va_list arg, char c);

#endif

