/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:11:42 by esobrinh          #+#    #+#             */
/*   Updated: 2022/11/18 21:33:26 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define HEX_LOWCASE "0123456789abcdef"
# define HEX_UPCASE "0123456789ABCDEF"
# define DEC_DIGITS "0123456789"

# ifdef __linux__
#  define NULLABLE "(nil)"
# else
#  define NULLABLE "0x0"
# endif

int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		ft_put_address(unsigned long long nbr);
int		ft_putnbr_base(long long nbr, char *base);
int		ft_puthex(unsigned long long nbr, char *base);

#endif