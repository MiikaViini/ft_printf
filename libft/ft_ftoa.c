/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/25 10:23:26 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_ftoa(long double num, int afterpoint)
{
	unsigned long long		l_dot;
	long double				r_dot;
	char					*res;
	char					*integer;
	int						remain;


	remain = 0;
	counter = 0;
	l_dot = (unsigned long long)num;
	r_dot = num - (long double)l_dot;
	integer = ft_strnew(21);
	//integer = ft_itoa(l_dot);
	if (afterpoint != 0)
		integer[ft_strlen(integer)] = '.';
	//r_dot = r_dot * ft_pow(10, afterpoint);
	while (afterpoint-- > 0)
	{
			r_dot = r_dot * 10.0;
			remain = (int)r_dot;
			r_dot = r_dot - (long double)remain;
			//r_dot = num - (long double)remain;
			//printf("r_dot %.20Lf\n", r_dot);
			printf("remain %d\n", remain);
			//printf("remain %d\n", remain);
			//remain = 0;
	}

	res = ft_strjoin(integer, ft_utoa((unsigned long long)r_dot));
	free(integer);
	return (res);
}
