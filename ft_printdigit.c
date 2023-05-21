/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:07:16 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/21 14:27:53 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printdi(int n)
{
	int		cont;
	char	*newstr;

	if (n < 0)
	{
		cont = 1;
	}
	else
	{
		cont = 0;
	}
	newstr = ft_itoa(n);
	cont += ft_prints(newstr);
	return (cont);
}

int	ft_printu(unsigned int n)
{
	int		cont;
	char	*newstr;

	newstr = ft_utoa(n);
	cont = ft_prints(newstr);
	return (cont);
}
