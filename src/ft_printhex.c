/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:14:37 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/15 17:41:54 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_hexlen(unsigned int n)
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

static void	ft_printhex(unsigned int n, char c)
{
	if (n >= 16)
	{
		ft_printhex(n / 16, c);
		ft_printhex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				ft_putchar(n - 10 + 'a');
			if (c == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
	return ;
}

int	ft_puthex(unsigned int num, char c)
{
	int	count;

	count = 0;
	if (num == 0)
		count = write(1, "0", 1);
	else
	{
		ft_printhex(num, c);
		count = ft_hexlen(num);
	}
	return (count);
}
