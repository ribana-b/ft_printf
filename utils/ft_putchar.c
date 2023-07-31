/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:25:32 by ribana-b          #+#    #+#             */
/*   Updated: 2023/07/31 07:45:16 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int character)
{
	if (write(1, &character, 1) == 1)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count] != '\0')
	{
		count += ft_putchar(str[count]);
	}
	return (count);
}

int	ft_putaddress(unsigned long int ptr)
{
	return (ft_putnbr_b2(ptr, LHEX_BASE));
}

int	ft_putnbr_b2(unsigned long n, char *base)
{
	static int		charcount;
	char			*newbase;
	unsigned long	b_length;

	charcount = 0;
	b_length = (unsigned long)ft_strlen(base);
	newbase = set_base(base, b_length);
	if (n >= b_length)
	{
		ft_putnbr_b2(n / b_length, newbase);
		charcount += ft_putchar(newbase[n % b_length]);
	}
	else
		charcount += ft_putchar(newbase[n % b_length]);
	free(newbase);
	return (charcount);
}
