/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:07:21 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/27 12:58:28 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	rounding(char *str, int index)
{
	if (str[index] == '.')
		rounding(str, index - 1);
	if (str[index] + 1 > '0' && str[index] + 1 <= '9')
		str[index] += 1;
	else if (str[index] == '9')
	{
		str[index] = '0';
		rounding(str, index - 1);
	}
}

static long double	fract_part(long double fract, int afterpoint, char *afterdot)
{
	int	remain;
	int	i;

	i = 1;
	remain = 0;
	while (afterpoint-- > 0)
	{
		fract = (long double)fract * 10.0;
		remain = (long long)fract;
		afterdot[i++] = remain + '0';
		fract = fract - (long double)remain;
	}
	return (fract);
}

static char	*rounded_fracts(long double fract, int afterpoint, char *afterdot, char **integer)
{
	// int		remain;
	char	*num;
	int		int_i;
	char	*temp;


	int_i = 0;
	
	// i = 1;
	// remain = 0;
	// while (afterpoint-- > 0)
	// {
	// 	fract = (long double)fract * 10.0;
	// 	remain = (long long)fract;
	// 	afterdot[i++] = remain + '0';
	// 	fract = fract - (long double)remain;
	// }
	//afterdot++;

	fract = fract_part(fract, afterpoint, afterdot);
	 if (((*integer[int_i] == '9' && afterdot[1] >= '5' ) && !afterpoint ) || (*integer[int_i] == '9' && afterpoint <= 1 && fract >= 0.5))
	 	temp = ft_strjoin("0", *integer);
	else
		temp = ft_strdup(*integer);
	num = ft_strjoin(temp, afterdot);
	ft_strdel(integer);
	ft_strdel(&temp);
	if (1.0 - fract < 0 + fract || (1.0 - fract == 0 + fract
			&& (num[ft_strlen(num) - 1] + 1 - '0') % 2 == 0))
	{
		rounding(num, ft_strlen(num) - 1);
	}
	return (num);
}



static char	*toarr(long double fract, unsigned long long inte, int afterpoint, int sign)
{
	char	*integer;
	char	*fractions;
	int		i;
	char	*output;

	i = 0;
	integer = ft_itoa(inte);
	if (afterpoint > 6)
		fractions = ft_strnew(afterpoint + 2);
	else
		fractions = ft_strnew(6 + 2);
	if (afterpoint > 0)
		fractions[i++] = '.';
	output = rounded_fracts(fract, afterpoint, fractions, &integer);
	//ft_strdel(&fractions);
	if (sign && fractions[0] != '-')
		integer = ft_strjoin("-", output);
	else
		integer = ft_strdup(output);
	ft_strdel(&output);
	ft_strdel(&fractions);
	return (integer);
}

// static char	*minuszero(int afterpoint)
// {
// 	char	*res;
// 	int		i;

// 	i = 0;
// 	res = ft_strnew(1 + afterpoint);
// 	res[i++] = '-';
// 	res[i++] = '0';
// 	res[i++] = '.';
// 	while (afterpoint-- > 0)
// 		res[i++] = '0';
// 	return (res);
// }

char	*ft_ftoa(long double num, int afterpoint)
{
	unsigned long long	l_dot;
	long double			r_dot;
	char				*res;
	int					sign;

	sign = 0;
	if (num < 0 || 1 / num < 0)
	{
		num = num * -1;
		sign = 1;
	}
	l_dot = (unsigned long long)num;
	r_dot = num - (long double)l_dot;
	res = toarr(r_dot, l_dot, afterpoint, sign);
	return (res);
}
