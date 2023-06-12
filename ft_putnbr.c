/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:25:36 by ribana-b          #+#    #+#             */
/*   Updated: 2023/06/12 18:54:09 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlena(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*set_base(char *base, int base_length)
{
	char	*newbase;
	int		count;

	count = 0;
	newbase = (char *)malloc(base_length * sizeof(char) + 1);
	while (count < base_length)
	{
		newbase[count] = base[count];
		count++;
	}
	newbase[count] = '\0';
	return (newbase);
}

int	ft_putnbr_b(long long n, char *base)
{
	static int	charcount;
	char		*newbase;
	int			b_length;

	charcount = 0;
	b_length = ft_strlena(base);
	newbase = set_base(base, b_length);
	if (n >= 0)
	{
		if (n >= b_length)
		{
			ft_putnbr_b(n / b_length, newbase);
			charcount += ft_putchar(newbase[n % b_length]);
		}
		else
			charcount += ft_putchar(newbase[n % b_length]);
	}
	else
	{
		ft_putchar('-');
		ft_putnbr_b(n * -1, newbase);
		charcount++;
	}
	free(newbase);
	return (charcount);
}
