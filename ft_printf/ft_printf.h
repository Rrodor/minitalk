/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:06:43 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/04 14:54:46 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_redirect(char c, va_list argptr, int l);
int		ft_printc(va_list argptr, int l);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_prints(va_list argptr, int l);
int		ft_strlen(char *str);
int		ft_putnbr_base(unsigned long long int n, int l, char *base);
int		ft_printp(va_list argptr, int l);
int		ft_printd(va_list argptr, int l);
int		ft_putnbr(int n, int l, char *base);
int		ft_printu(va_list argptr, int l);
int		ft_printx(va_list argptr, int l);
int		ft_printxm(va_list argptr, int l);

#endif
