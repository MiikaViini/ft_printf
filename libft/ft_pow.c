/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:53:47 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/25 16:09:15 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double num, double pow)
{
	double	res;
	int		counter;

	res = 1;
	counter = -1;
	if (pow < 0)
		return (0);
	while (++counter < pow)
		res *= num;
	return (res);
}
