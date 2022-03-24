/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/24 13:52:45 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_ftoa(long double num, int afterpoint)
{
	unsigned long long			l_dot;
	long double				r_dot;
	char		*res;

	l_dot = (unsigned long long)num;
	r_dot = num - (long double)l_dot;
	res = ft_strnew(50);
	res = ft_itoa(l_dot);
	if (afterpoint != 0)
		res[ft_strlen(res)] = '.';
	r_dot = r_dot * ft_pow(10, afterpoint);
	//printf("%f\n", r_dot);
	res = ft_strjoin(res, ft_utoa((unsigned long long)r_dot));
	return (res);
}
