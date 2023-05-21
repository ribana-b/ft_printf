/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:59:43 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/21 11:40:37 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_format(const char format, int cont, va_list arg)
{
	if (format == 'c')
		cont += ft_printc(va_arg(arg, int));
	else if (format == 's')
		cont += ft_prints(va_arg(arg, char *));
	else if (format == 'p')
		cont += ft_prints(va_arg(arg, char *));
	else if (format == 'd')
		cont += ft_prints(va_arg(arg, char *));
	else if (format == 'i')
		cont += ft_prints(va_arg(arg, char *));
	else if (format == 'u')
		cont += ft_prints(va_arg(arg, char *));
	else if (format == 'x')
		cont += ft_prints(va_arg(arg, char *));
	else if (format == 'X')
		cont += ft_prints(va_arg(arg, char *));
	else if (format == '%')
		cont += ft_printc('%');
	return (cont);
}

int	ft_printf(const char *s, ...)
{
	int		cont;
	int		ccont;
	int		scont;
	va_list	arg;

	va_start(arg, s);
	scont = 0;
	ccont = 0;
	cont = 0;
	while (s[scont])
	{
		if (*s == '%')
		{
			ccont += ft_format(s[scont + 1], cont, arg);
			scont++;
		}
		else
			ccont += ft_printc(s[scont]);
		scont++;
	}
	va_end(arg);
	return (ccont);
}

//This is for testing
#include <stdio.h>

int	main(void)
{
	printf("printf: Hola\n");
	ft_printf("ft_printf: Hola\n\n");
	char	s[] = "Hola";
	printf("printf: %%c: %c %%s: %s %%p: %p\n", s[0], s, s);
	ft_printf("ft_printf: %%c: %c %%s: %s %%p: %p\n\n", s[0], s, s);
	int	n = 2147483647;
	printf("printf: %%d: %d %%i: %i\n", n, n);
	ft_printf("ft_printf: %%d: %d %%i: %i\n\n", n, n);
	unsigned int n2 = 4294967295;
	printf("printf: %%u: %u\n", n2);
	ft_printf("ft_printf: %%u: %u\n\n", n2);
	int	n3 = 42;
	printf("printf: %%x: %x %%X: %X\n", n3, n3);
	ft_printf("ft_printf: %%x: %x %%X: %X\n\n", n3, n3);
	printf("printf: %%: %%\n");
	ft_printf("ft_printf: %%: %%\n\n");
}