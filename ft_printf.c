/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:59:43 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/20 20:05:46 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_format(const char format, const char *s, int cont, va_list arg)
{
	if (format == 'c')
		cont += ft_putchar(*s, char);
	else if (format == 's')
		cont += ft_putstr(s, char *)
	else if (format == 'p')
	else if (format == 'd')
	else if (format == 'i')
	else if (format == 'u')
	else if (format == 'x')
	else if (format == 'X')
	else if (format == '%')
		cont += ft_putchar('%', char);
	return (cont);
}

int	ft_printf(const char *s, ...)
{
	int		cont;
	va_list	arg;

	if (!s)
	{
		return (0);
	}
	scont = 0;
	cont = 0;
	while (s[scont])
	{
		if (*s == '%')
		{
			cont += ft_format(s[++scont], (s + scont), cont, va_start(arg));
		}
		scont++;
		cont++;
	}
	va_end(arg);
	return (cont);
}
