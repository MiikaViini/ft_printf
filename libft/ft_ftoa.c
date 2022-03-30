/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/30 14:48:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*toarr(long double fract, unsigned long long inte, int afterpoint, int sign)
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

static char	*minuszero(int afterpoint)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(1 + afterpoint);
	res[i++] = '-';
	res[i++] = '0';
	res[i++] = '.';
	while (afterpoint-- > 0)
		res[i++] = '0';
	return (res);
}

char	*ft_ftoa(long double num, int afterpoint)
{
	unsigned long long	l_dot;
	long double			r_dot;
	char				*res;
	int					sign;

	sign = 0;
	if (num < 0)
	{
		num = num * -1;
		sign = 1;
	}
	else if (1 / num < 0)
		return (minuszero(afterpoint));
	else if (check_infinity(num) == 0)
	l_dot = (unsigned long long)num;
	r_dot = num - (long double)l_dot;
	res = toarr(r_dot, l_dot, afterpoint, sign);
	return (res);
}
