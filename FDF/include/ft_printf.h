/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:27:51 by eorer             #+#    #+#             */
/*   Updated: 2023/02/22 14:26:05 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <limits.h>

void	ft_putchar_count_fd(char c, int fd, int *count);
void	ft_putnbr_count_fd(int nbr, int fd, int *count);
void	ft_putstr_count_fd(char *str, int fd, int *count);
void	ft_unsigned_putnbr_fd(unsigned int nbr, int fd, int *count);
void	ft_putnbr_hexa_fd(unsigned int n, char *base, int fd, int *count);
void	ft_put_adress(void *ptr, int fd, int *count);
void	ft_print_arg(va_list arg, char c, int	*count);
char	*ft_strrev(char *str);
//int		ft_format(va_list arg, char *str, int *count);
int		ft_printf(const char *str, ...);

#endif
