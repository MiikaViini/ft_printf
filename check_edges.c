/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:12:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/02 14:54:22 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_edges(t_modifiers *mods, char *format, long long num)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (mods->dot && mods->precision == 0 && num == 0 && !mods->width && !mods->d_space)
	{
		temp = ft_strnew(1);
		return (temp);
	}
	if (mods->o_zero && !mods->precision && !num || !mods->width && mods->dot && mods->precision == 0 && !num)
	{
		temp = ft_strdup("0");
		return (temp);
	}
	else if (mods->dot && mods->precision == 0 && num == 0)
	{
		while (format[i])
		{
			if (ft_isdigit(format[i]))
				format[i] = ' ';
			i++;
		}
		if (mods->d_space && mods->width <= 1)
			temp = ft_strdup(format + mods->space);
		else
			temp = ft_strdup(format);
			//format++;

		return (temp);
	}
	temp = ft_strnew(ft_strlen(format));
	if ((!mods->width && !mods->precision && !mods->zero) || !temp)
	{
		ft_strdel(&temp);
		temp = ft_strdup(format);
		return (temp);
	}
	if (mods->zero && mods->width && mods->hash && mods->capital)
		temp = ft_strjoin("0x", format + (mods->hash * 2));
	else if (mods->zero && mods->width && mods->hash && !mods->capital)
		temp = ft_strjoin("0X", format + (mods->hash * 2));
	else
	{
		ft_strdel(&temp);
		temp = ft_strdup(format);
		//ft_strdel(&format);
	}
	// format = temp;
	// ft_strdel(&temp);
	return (temp);
}

char	*check_infinity(double num, t_modifiers *mods)
{
	double	posinf;
	double	neginf;
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(4);
	posinf = 1.0 / 0;
	neginf = -1.0 / 0;
	if (num == posinf && !mods->plus && !mods->space)
		res = ft_strcpy(res, "inf");
	else if (num == posinf && mods->plus)
		res = ft_strcpy(res, "+inf");
	else if (num == posinf && mods->space)
		res = ft_strcpy(res, " inf");
	else if (num == neginf)
		res = ft_strcpy(res, "-inf");
	else if ((long double)num != (long double)num)
		res = ft_strcpy(res, "nan");
	return (res);
}
