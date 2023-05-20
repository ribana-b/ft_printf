/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:57:52 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/20 20:01:03 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(const char c, va_list arg)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s, va_list arg)
{
	int	cont;

	cont = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (0)
	}
	while (s[cont])
	{
		write (1, &s[cont], 1);
		cont++;
	}
	return (cont);
}
