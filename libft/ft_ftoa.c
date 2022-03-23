/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:54:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/23 09:42:43 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(double num, int afterpoint)
{
	int			l_dot;
	double	r_dot;
	char		*res;

	l_dot = (int)num;
	r_dot = num - (double)l_dot;
	res = ft_strnew(20);
	res = ft_itoa(l_dot);
	if (afterpoint != 0)
		res[ft_strlen(res)] = '.';
	r_dot = r_dot * ft_pow(10, afterpoint);
	res = ft_strjoin(res, ft_itoa((int)r_dot));
	return (res);
}
