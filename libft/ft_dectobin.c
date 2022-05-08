/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:48:10 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/08 21:56:40 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dectobin(long long num)
{
	char				*bin;
	size_t				i;
	unsigned long long	min;

	i = 0;
	bin = ft_strnew(64);
	min = num;
	if (num < 0)
	{
		if (num == -32768)
			num++;
		else if (num == -2147483648)
			num++;
		else if (num == -9223372036854775807 - 1)
			num++;
		min = num * -1;
	}
	while (min > 0)
	{
		bin[i++] = min % 2 + '0';
		min /= 2;
	}
	if (num < 0)
		bin[i++] = '-';
	return (ft_strrev(bin));
}
