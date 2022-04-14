/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/14 07:45:37 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*rounded_fracts(long double fract, int afterpoint, char *afterdot)
{
	int		remain;
	int		i;

	i = 1;
	remain = 0;
	while (afterpoint-- > 0)
	{
		fract = fract * 10.0;
		remain = (int)fract;
		afterdot[i++] = remain + '0';
		fract = fract - (long double)remain;
	}
	fract = fract * 10.0;
	remain = (int)fract;
	i--;
	if (remain > 5 && remain < 9)
		afterdot[i] = afterdot[i] + 1;
	else if (remain == 5)
		if ((ft_atoi(&afterdot[i]) + 1) % 2 == 0)
			afterdot[i] = afterdot[i] + 1;
	return (afterdot);
}

static char	*toarr(long double fract, unsigned long long inte, int afterpoint, int sign)
{
	char	*integer;
	char	*fractions;
	int		i;
	char	*output;

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
	fractions = rounded_fracts(fract, afterpoint, fractions);
	output = ft_strjoin(integer, fractions);
	ft_strdel(&integer);
	ft_strdel(&fractions);
	return (output);
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
	l_dot = (unsigned long long)num;
	r_dot = num - (long double)l_dot;
	res = toarr(r_dot, l_dot, afterpoint, sign);
	return (res);
}
