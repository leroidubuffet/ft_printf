/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:59:34 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/14 19:11:59 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_dnum(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static void	ft_writenbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_writenbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int	ft_putunint(unsigned int num)
{
	int	count;

	if (num < 10)
	{
		num += '0';
		write(1, &num, 1);
		return (1);
	}
	count = ft_putunint(num / 10);
	num = '0' + num % 10;
	write(1, &num, 1);
	return (count + 1);
}

int	ft_putnbr(int num)
{
	int		count;

	ft_writenbr(num);
	count = ft_dnum(num);
	return (count);
}
