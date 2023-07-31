/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:26:41 by ribana-b          #+#    #+#             */
/*   Updated: 2023/07/31 07:46:18 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_format(const char *str, va_list arg, int charcount)
{
	if (*str == '%')
		charcount += ft_putchar('%');
	else if (*str == 'c')
		charcount += ft_putchar(va_arg(arg, int));
	else if (*str == 's')
		charcount += ft_putstr(va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
		charcount += ft_putnbr_b(va_arg(arg, int), DEC_BASE);
	else if (*str == 'u')
		charcount += ft_putnbr_b(va_arg(arg, unsigned int), DEC_BASE);
	else if (*str == 'x')
		charcount += ft_putnbr_b(va_arg(arg, unsigned int), LHEX_BASE);
	else if (*str == 'X')
		charcount += ft_putnbr_b(va_arg(arg, unsigned int), UHEX_BASE);
	else if (*str == 'p')
	{
		charcount += ft_putstr("0x");
		charcount += ft_putaddress(va_arg(arg, unsigned long int));
	}
	return (charcount);
}

int	ft_printf(const char *str, ...)
{
	int		charcount;
	int		strpos;
	va_list	arg;

	va_start(arg, str);
	charcount = 0;
	strpos = 0;
	while (str[strpos] != '\0')
	{
		if (str[strpos] == '%')
		{
			strpos++;
			charcount = ft_printf_format(&str[strpos], arg, charcount);
		}
		else
		{
			write(1, &str[strpos], 1);
			charcount++;
		}
		strpos++;
	}
	va_end(arg);
	return (charcount);
}
