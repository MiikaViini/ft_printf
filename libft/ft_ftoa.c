/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/25 17:43:07 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*toarr(long double fract, long long inte, int afterpoint, int sign)
{
	char	*integer;
	char	*fractions;
	int		i;
	int		remain;

	i = 0;
	if (sign)
		integer = ft_itoa(inte * (-1));
	else
		integer = ft_itoa(inte);
	if (afterpoint > 6)
		fractions = ft_strnew(afterpoint + i + 2);
	else
		fractions = ft_strnew(6 + i + 2);
	if (afterpoint != 0)
		fractions[i++] = '.';
	while (afterpoint-- > 0)
	{
		fract = fract * 10.0;
		remain = (int)fract;
		fractions[i++] = remain + '0';
		fract = fract - (long double)remain;
	}
	fractions = ft_strjoin(integer, fractions);
	return (fractions);
}

char	*ft_ftoa(long double num, int afterpoint)
{
	long long	l_dot;
	long double	r_dot;
	char		*res;
	int			sign;

	sign = (int)num;
	
	if (1 / num < 0)
	{
		printf("something");
		num = num * -1;
		sign = 1;
	}
	
	l_dot = (long long)num;
	r_dot = num - (long double)l_dot;
	res = toarr(r_dot, l_dot, afterpoint, sign);
	return (res);
}
