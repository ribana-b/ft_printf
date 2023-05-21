/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:33:03 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/21 10:55:39 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printxX(const char format, va_list arg)
{
	int	cont;
	int	num;

	write(1, "0", 1);
	if (format == 'x')
		write(1, "x", 1);
	else if (format == 'X')
		write (1, "X", 1);
	cont = 2;
	num = ft_atoi()
	
}

int	ft_printp(void *ptr, va_list arg)
{

}