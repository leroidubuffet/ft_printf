/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:01:33 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/15 17:39:30 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_numlen(unsigned int n);
int	ft_printf(const char *str, ...);
int	ft_putptr(void *ptr);
int	ft_putchar(int c);
int	ft_putnbr(int num);
int	ft_putptr(void *ptr);
int	ft_putstr(char *str);
int	ft_puthex(unsigned int num, char c);
int	ft_putunint(unsigned int num);

#endif
