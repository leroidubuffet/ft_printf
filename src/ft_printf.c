/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:14:37 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/04 15:17:58 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_parseargs(va_list args, const char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_putchar(va_arg (args, int));
	else if (str == 's')
		count += ft_putstr(va_arg (args, char *));
	else if (str == 'p')
		count += ft_putptr(va_arg (args, void *));
	else if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg (args, int));
	else if (str == 'u')
		count += ft_putunint(va_arg (args, unsigned int));
	else if (str == 'X' || str == 'x')
		count += ft_puthex(va_arg (args, unsigned int), str);
	else if (str == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	if (!str)
		return (1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parseargs(args, str[i + 1]);
			i++;
		}
		else
			count += write(1, &(str[i]), 1);
		i++;
	}
	va_end(args);
	return (count);
}
