/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@42student.malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:00:04 by ribana-b          #+#    #+#             */
/*   Updated: 2023/06/15 02:50:47 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define DEC_BASE "0123456789"
# define LHEX_BASE "0123456789abcdef"
# define UHEX_BASE "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		ft_printf_format(const char *str, va_list arg, int charcount);
int		ft_putchar(int character);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
char	*set_base(char *base, int base_length);
int		ft_putnbr_b(long long n, char *base);
int		ft_putnbr_b2(unsigned long n, char *base);
int		ft_putaddress(unsigned long int ptr);

#endif
