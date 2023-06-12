/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@42student.malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:25:32 by ribana-b          #+#    #+#             */
/*   Updated: 2023/06/12 15:10:28 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int character)
{
	return (write(1, &character, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
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

int	ft_putaddress(void *ptr)
{
	int		count;
	char	*address;

	address = ptr;
	count = 2;
	write (1, "0x", 2);
	write (1, &address, sizeof(address));
	count += sizeof(address);
	return (count);
}
