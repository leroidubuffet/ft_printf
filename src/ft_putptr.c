/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:14:37 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/15 17:38:41 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_ptrlen(uintptr_t p)
{
	int	count;

	count = 0;
	while (p != 0)
	{
		count++;
		p = p / 16;
	}
	return (count);
}

static void	ft_printptr(uintptr_t p)
{
	if (p >= 16)
	{
		ft_printptr(p / 16);
		ft_printptr(p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar(p + '0');
		else
			ft_putchar(p - 10 + 'a');
	}
}

int	ft_putptr(void *ptr)
{
	uintptr_t	p;
	int			count;

	p = (uintptr_t)ptr;
	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
	{
		ft_printptr(p);
		count += ft_ptrlen(p);
	}
	return (count);
}
