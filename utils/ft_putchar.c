/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@42student.malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:25:32 by ribana-b          #+#    #+#             */
/*   Updated: 2023/06/16 22:03:56 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int character)
{
	return (write(1, &character, 1));
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
	if (ptr == 0)
	{
		return (write(1, "(nil)", 5));
	}
	else
	{
		return (write(1, "0x", 2) + ft_putnbr_b(ptr, LHEX_BASE));
	}
}
