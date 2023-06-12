/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@42student.malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:26:41 by ribana-b          #+#    #+#             */
/*   Updated: 2023/06/12 15:39:36 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(const char *str, va_list arg, int charcount)
{
	if (*str == '%')
		charcount += ft_putchar('%');
	else if (*str == 'c')
		charcount += ft_putchar(va_arg(arg, int));
	else if (*str == 's')
		charcount += ft_putstr(va_arg(arg, char *));
	else if (*str == 'd')
		charcount += ft_putnbr_b(va_arg(arg, int), DEC_BASE);
	else if (*str == 'i')
		charcount += ft_putnbr_b(va_arg(arg, int), DEC_BASE);
	else if (*str == 'u')
		charcount += ft_putnbr_b(va_arg(arg, unsigned int), DEC_BASE);
	else if (*str == 'x')
		charcount += ft_putnbr_b(va_arg(arg, unsigned int), LHEX_BASE);
	else if (*str == 'X')
		charcount += ft_putnbr_b(va_arg(arg, unsigned int), UHEX_BASE);
 	else if (*str == 'p')
	{
		charcount += write(1, "0x", 2);
		charcount += ft_putnbr_b(va_arg(arg, unsigned int), UHEX_BASE);
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
			charcount = ft_printf_format(str, arg, charcount);
			strpos++;
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


#include <stdio.h>

int	main(void)
{
	char			chartest = 42;
	char			*stringtest = "Probando el string";
	int				dinumtest = -2147483648;
	unsigned int	unumtest = 0xFFFFFFFF;
	int				hextest = 0xFFFF;
	char			*adresstest = "Probando el adress";

	printf("\033[1;33mValores printf original\033[0m\n");
	printf("\033[34mchartest value:\033[0m %d\n", printf("c: %c\n", chartest));
	printf("\033[34mstringtest value:\033[0m %d\n", printf("s: %s\n", stringtest));
	printf("\033[34mdnumtest value:\033[0m %d\n", printf("d: %d\n", dinumtest));
	printf("\033[34minumtest value:\033[0m %d\n", printf("i: %i\n", dinumtest));
	printf("\033[34munumtest value:\033[0m %d\n", printf("u: %u\n", unumtest));
	printf("\033[34madresstest value:\033[0m %d\n", printf("p: %p\n", adresstest));
	printf("\033[34mhextest value:\033[0m %d\n", printf("x: %x\n", hextest));
	printf("\033[34mHEXtest value:\033[0m %d\n", printf("X: %X\n", hextest));
	printf("\033[34m%%test value:\033[0m %d\n", printf("%%: %%\n"));

	printf("\033[1;33mValores mi printf\033[0m\n");
	printf("\033[34mchartest value:\033[0m %d\n", ft_printf("c: %c\n", chartest));
	printf("\033[34mstringtest value:\033[0m %d\n", ft_printf("s: %s\n", stringtest));
	printf("\033[34mdnumtest value:\033[0m %d\n", ft_printf("d: %d\n", dinumtest));
	printf("\033[34minumtest value:\033[0m %d\n", ft_printf("i: %i\n", dinumtest));
	printf("\033[34munumtest value:\033[0m %d\n", ft_printf("u: %u\n", unumtest));
	printf("\033[34madresstest value:\033[0m %d\n", ft_printf("p: %p\n", adresstest));
	printf("\033[34mhextest value:\033[0m %d\n", ft_printf("x: %x\n", hextest));
	printf("\033[34mHEXtest value:\033[0m %d\n", ft_printf("X: %X\n", hextest));
	printf("\033[34m%%test value:\033[0m %d\n", ft_printf("%%: %%\n"));

	return (0);
}