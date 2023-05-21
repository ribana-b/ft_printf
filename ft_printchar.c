/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:57:52 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/21 11:40:43 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printc(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_prints(const char *s)
{
	int	cont;

	cont = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[cont])
	{
		write (1, &s[cont], 1);
		cont++;
	}
	return (cont);
}
