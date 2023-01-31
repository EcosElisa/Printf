/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:59:34 by esobrinh          #+#    #+#             */
/*   Updated: 2022/11/19 01:11:20 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *str)
{
	int	c_printed;

	c_printed = 0;
	if (str)
	{
		while (str[c_printed])
		{
			write(1, &str[c_printed], 1);
			c_printed++;
		}
	}
	else
		c_printed += ft_putstr("(null)");
	return (c_printed);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int	len_base;
	int	c_printed;

	c_printed = 0;
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		c_printed += ft_putchar('-');
	}
	if (nbr < len_base)
		c_printed += ft_putchar(base[nbr]);
	else
	{
		c_printed += ft_putnbr_base(nbr / len_base, base);
		c_printed += ft_putnbr_base(nbr % len_base, base);
	}
	return (c_printed);
}

int	ft_put_address(unsigned long long nbr)
{
	int	c_printed;

	c_printed = 0;
	if (!nbr)
	{
		c_printed += ft_putstr(NULLABLE);
		return (c_printed);
	}
	c_printed += ft_putstr("0x");
	c_printed += ft_puthex(nbr, HEX_LOWCASE);
	return (c_printed);
}

int	ft_puthex(unsigned long long nbr, char *base)
{
	int	c_printed;

	c_printed = 0;
	if (nbr < 16)
		c_printed += ft_putchar(base[nbr]);
	else
	{
		c_printed += ft_puthex(nbr / 16, base);
		c_printed += ft_puthex(nbr % 16, base);
	}
	return (c_printed);
}
