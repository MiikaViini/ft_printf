/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:30:47 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/25 16:31:31 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(long long n)
{
	unsigned char	len;

	len = 0;
	if (n < 0)
	{
		n = ~n;
		n++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}