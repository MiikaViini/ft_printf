/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:07:21 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/19 19:49:22 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	rounding(char *str, int index)
{
	if (str[index] == '.')
		rounding(str, index - 1);
	if (str[index] + 1 >= '0' && str[index] + 1 <='9')
		str[index] += 1;
	else if (str[index] == '9')
	{
		str[index] = '0';
		rounding(str, index - 1);
	}
}

static char	*rounded_fracts(long double fract, int afterpoint, char *afterdot, char **integer)
{
	int		remain;
	int		i;
	char	*num;
	int		int_i;
	int		temp;

	temp = afterpoint;
	int_i = 0;
	i = 1;
	remain = 0;
	while (afterpoint-- > 0)
	{
		fract = (long double)fract * 10.0;
		remain = (long long)fract;
		afterdot[i++] = remain + '0';
		fract = fract - (long double)remain;
		//printf("%Lf\n", fract);
	}

	 if (((*integer[int_i] == '9' && afterdot[1] >= '5' ) && !temp )|| (*integer[int_i] == '9' && temp <= 1 && fract >= 0.5))
	 	*integer = ft_strjoin("0", *integer);
	num = ft_strjoin(*integer, afterdot);
	if (1.0 - fract < 0 + fract || (1.0 - fract == 0 + fract
			&& (num[ft_strlen(num) - 1] + 1 - '0') % 2 == 0))
	{
		//*integer = ft_strjoin("0", *integer);
		rounding(num, ft_strlen(num) - 1);
	}
	// printf("%s", num);
	// exit(1);

	// if (num[0] == '0')
	// 	num++;
	return (num);
}

static char	*toarr(long double fract, unsigned long long inte, int afterpoint, int sign)
{
	char	*integer;
	char	*fractions;
	int		i;
	//char	*output;

	i = 0;
	// if (sign)
	// 	inte = inte * -1;
	integer = ft_itoa(inte);
	if (afterpoint > 6)
		fractions = ft_strnew(afterpoint + 2);
	else
		fractions = ft_strnew(6 + 2);
	if (afterpoint > 0)
		fractions[i++] = '.';
	fractions = rounded_fracts(fract, afterpoint, fractions, &integer);
	//output = ft_strjoin(integer, fractions);
	if (sign && fractions[0] != '-')
		fractions = ft_strjoin("-", fractions);
	ft_strdel(&integer);
	//ft_strdel(&fractions);
	return (fractions);
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
	// printf("%s", res);
	// exit(1);
	return (res);
}
