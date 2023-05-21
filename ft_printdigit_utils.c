/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:59:22 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/21 14:19:22 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	numlen(int n)
{
	unsigned int	newnum;
	int				cont;

	if (n < 0)
	{
		newnum = n * -1;
	}
	else
	{
		newnum = n;
	}
	cont = 1;
	while ((newnum / 10) > 0)
	{
		newnum /= 10;
		cont++;
	}
	return (cont);
}

char	*assignmalloc(int n, int bytes)
{
	char	*str;

	if (n < 0)
	{
		str = (char *)malloc(bytes * sizeof(char) + 2);
	}
	else
	{
		str = (char *)malloc(bytes * sizeof(char)  + 1);
	}
	if (!str)
	{
		return (0);
	}
	return (str);
}

char	*numtostr(char *str, int n, int nlen)
{
	unsigned int	newnum;

	if (n < 0)
	{
		newnum = n * -1;
	}
	else
	{
		newnum = n;
	}
	*(str + nlen) = '\0';
	while (nlen--)
	{
		*(str + nlen) = (newnum % 10) + '0';
		newnum /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		nlen;

	nlen = numlen(n);
	newstr = assignmalloc(n, nlen);
	if (!newstr)
	{
		return (0);
	}
	if (n < 0)
	{
		*newstr = '-';
		numtostr((newstr + 1), n, nlen);
	}
	else
	{
		numtostr(newstr, n, nlen);
	}
	return (newstr);
}

char	*ft_utoa(unsigned int n)
{
	char	*newstr;
	int		nlen;

	nlen = numlen(n);
	newstr = assignmalloc(n, nlen);
	if (!newstr)
	{
		return (0);
	}
	numtostr(newstr, n, nlen);
	return (newstr);
}