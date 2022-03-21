/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:38:53 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/20 20:15:40 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	// if (n == -2147483648)
	// {
	// 	ft_putchar('2');
	// 	n = 147483648;
	// }
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar((char)n + '0');
	}
}
