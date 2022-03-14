/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:30:23 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/14 14:39:58 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabase(int num, int base)
{
	int	res;
	int	count;

	count = 0;
	res = 0;
	if ((base < 2 && base > 16) || num == 0)
		return (ft_itoa(res));
	while (num)
	{
		res += num % base + ft_pow(base, count);
		num /= base;
		count += 10;
	}
	return (ft_itoa(res));
}
