/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:12:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/30 21:31:59 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_edges(t_modifiers *mods, char *format, int num)
{
	char	*res;

	res = ft_strnew(1);
	if (mods->dot == 1 && mods->precision == 0 && num == 0)
		return (res);
	free(res);
	return (format);
}

char	*check_infinity(double num)
{
	double	posinf;
	double	neginf;
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(4);
	posinf = 1.0 / 0;
	neginf = -1.0 / 0;
	if (num == posinf)
		res = strcpy(res, "inf");
	else if (num == neginf)
		res = strcpy(res, "-inf");
	else if (num != num)
		res = strcpy(res, "nan");
	return (res);
}
