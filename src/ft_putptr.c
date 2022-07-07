/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:14:37 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/04 13:46:34 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_ptrlen(uintptr_t n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

static void	ft_printptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_printptr(n / 16);
		ft_printptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_putptr(void *ptr)
{
	uintptr_t	n;
	int			count;

	n = (uintptr_t)ptr;
	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
	{
		ft_printptr(n);
		count += ft_ptrlen(n);
	}
	return (count);
}
