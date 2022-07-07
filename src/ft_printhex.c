/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:14:37 by ybolivar          #+#    #+#             */
/*   Updated: 2022/06/30 12:39:19 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_hexlen(unsigned int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

static void	ft_printhex(unsigned int num, char c)
{
	if (num >= 16)
	{
		ft_printhex(num / 16, c);
		ft_printhex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (c == 'x')
				ft_putchar(num - 10 + 'a');
			if (c == 'X')
				ft_putchar(num - 10 + 'A');
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
