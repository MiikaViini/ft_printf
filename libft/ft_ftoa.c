/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/15 22:23:16 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_ftoa(float num, int afterpoint)
{
	int		l_dot;
	float	r_dot;
	char	*res;

	l_dot = (int)num;
	r_dot = num - (float)l_dot;
	res = ft_strnew(20);
	res = ft_itoa(l_dot);
	if (afterpoint != 0)
		res[ft_strlen(res)] = '.';
	r_dot = r_dot * ft_pow(10, afterpoint);
	res = ft_strjoin(res, ft_itoa((int)r_dot));
	return (res);
}
