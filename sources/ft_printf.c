/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:56:38 by esobrinh          #+#    #+#             */
/*   Updated: 2022/11/19 00:46:39 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_conversion_specifiers(char c, va_list arg_ptr)
{
	int	c_printed;

	c_printed = 0;
	if (c == 'c')
		c_printed += ft_putchar(va_arg(arg_ptr, int));
	else if (c == 's')
		c_printed += ft_putstr(va_arg(arg_ptr, char *));
	else if (c == 'd' || c == 'i')
		c_printed += ft_putnbr_base(va_arg(arg_ptr, int), DEC_DIGITS);
	else if (c == 'u')
		c_printed += ft_putnbr_base(va_arg(arg_ptr, unsigned int), DEC_DIGITS);
	else if (c == 'x')
		c_printed += ft_putnbr_base(va_arg(arg_ptr, unsigned int), HEX_LOWCASE);
	else if (c == 'X')
		c_printed += ft_putnbr_base(va_arg(arg_ptr, unsigned int), HEX_UPCASE);
	else if (c == 'p')
		c_printed += ft_put_address(va_arg(arg_ptr, unsigned long long));
	else if (c == '%')
		return (write(1, "%", 1));
	return (c_printed);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		arg_ptr;
	int			n_printed;

	i = 0;
	n_printed = 0;
	va_start(arg_ptr, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			n_printed += ft_conversion_specifiers(str[++i], arg_ptr);
		else
			n_printed += write(1, &str[i], 1);
		i++;
	}
	va_end(arg_ptr);
	return (n_printed);
}
