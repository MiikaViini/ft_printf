/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:30:23 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/15 20:41:22 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_over_sixteen(int num, int base, int flag)
{
	char	*res;
	int		remainder;
	int		i;

	remainder = 0;
	res = ft_strnew(20);
	i = 0;
	while (num)
	{
		remainder = num % base;
		if (remainder > 9)
			res[i++] = 'A' + (remainder - 10) + (CAPITAL * flag);
		else
			res[i++] = remainder + '0';
		num /= base;
	}
	return (ft_strrev(res));
}

char	*ft_itoabase(int num, int base, int flag)
{
	int	res;
	int	count;
	int	remainder;

	res = 0;
	count = 1;
	remainder = 0;
	if (base > 15)
		return (ft_over_sixteen(num, base, flag));
	while (num)
	{
		remainder = num % base;
		res += remainder * count;
		num /= base;
		count *= 10;
	}
	return (ft_itoa(res));
}
