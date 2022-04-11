/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:12:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/11 11:19:36 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_edges(t_modifiers *mods, char *format, long long num)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;

	if (mods->o_zero)
		return ("0");
	if (mods->dot && mods->precision == 0 && num == 0 && !mods->width)
		return ("");
	else if (mods->dot && mods->precision == 0 && num == 0 && mods->width)
	{
		while (format[i])
		{
			if (ft_isdigit(format[i]))
				format[i] = ' ';
			i++;
		}
		return (format);
	}
	temp = ft_strnew(ft_strlen(format));
	if ((!mods->width && !mods->precision && !mods->zero) || !temp)
	{
		ft_strdel(&temp);
		return (format);
	}
	if (mods->zero && mods->width && mods->hash && mods->capital)
		temp = ft_strjoin("0x", format + (mods->hash * 2));
	else if (mods->zero && mods->width && mods->hash && !mods->capital)
		temp = ft_strjoin("0X", format + (mods->hash * 2));
	else
	{
		ft_strdel(&temp);
		return (format);
	}
	format = temp;
	ft_strdel(&temp);
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
		res = ft_strcpy(res, "inf");
	else if (num == neginf)
		res = ft_strcpy(res, "-inf");
	else if (num != num)
		res = ft_strcpy(res, "nan");
	return (res);
}
