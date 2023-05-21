/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b < ribana-b@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:00:04 by ribana-b          #+#    #+#             */
/*   Updated: 2023/05/21 14:27:55 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// Printf
int		ft_printf(const char *s, ...);
int		ft_format(const char format, va_list arg);

//Print char
int		ft_printc(int c);
int		ft_prints(const char *s);

//Print hex
int	ft_printxX(int n, char format);
int	ft_printp(void *ptr);

//Print digit

int	ft_printdi(int n);
int	ft_printu(unsigned int n);

//Print digit utils
int		numlen(int n);
char	*assignmalloc(int n, int bytes);
char	*numtostr(char *str, int n, int nlen);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);

#endif
