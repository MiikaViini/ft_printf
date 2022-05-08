/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:48:10 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/08 22:18:19 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	treat_minus(long long num, int *sign)
{
	if (num == -32768)
		num++;
	else if (num == -2147483648)
		num++;
	else if (num == -9223372036854775807 - 1)
		num++;
	num = num * -1;
	*sign = 1;
	return (num);
}

char	*ft_dectobin(long long num)
{
	char				*bin;
	size_t				i;
	int					sign;

	i = 0;
	bin = ft_strnew(64);
	sign = 0;
	bin[0] = '0';
	if (num < 0)
		num = treat_minus(num, &sign);
	while (num)
	{
		bin[i++] = num % 2 + '0';
		num /= 2;
	}
	if (sign)
		bin[i++] = '-';
	return (ft_strrev(bin));
}
