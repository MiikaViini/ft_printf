/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:23:42 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/03 14:23:17 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_null(char *str, t_modifiers *mods, int count, char c)
{
	char	*output;

	output = treat_width(str, mods, ft_strlen(str));
	if (mods->minus)
	{
		ft_putchar(c);
		count = ft_putstrlen(output + 1);
		ft_strdel(&str);
		ft_strdel(&output);
		return (count + 1);
	}
	else if (mods->width)
	{
		count = ft_putstrlen(output + 1);
		ft_putchar(c);
		ft_strdel(&str);
		ft_strdel(&output);
		return (count + 1);
	}
	ft_putchar(c);
	ft_strdel(&str);
	ft_strdel(&output);
	return (1);
}

int	c_specifier(va_list args, t_modifiers *mods)
{
	char	*str;
	char	*output;
	int		c;
	int		count;

	if (mods->width)
		str = ft_strnew(mods->width);
	else
		str = ft_strnew(1);
	c = va_arg(args, int );
	str[0] = c;
	if (!c)
		return (treat_null(str, mods, count, c));
	output = treat_width(str, mods, ft_strlen(str));
	ft_putstr(output);
	count = ft_strlen(output);
	ft_strdel(&str);
	ft_strdel(&output);
	return (count);
}
