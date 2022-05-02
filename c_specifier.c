/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:23:42 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/02 20:34:37 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_null(char *str, t_modifiers *mods, int count)
{
	char	*output

	output = treat_width(str, mods, ft_strlen(str), c);
	if (mods->minus)
	{
		ft_putchar(c);
		ft_putstr(output + 1);
		count = ft_strlen(output + 1);
		ft_strdel(&str);
		ft_strdel(&output);
		return (count + 1);
	}
	else if (mods->width)
	{
		ft_putstr(output + 1);
		ft_putchar(c);
		count = ft_strlen(output);
		ft_strdel(&str);
		ft_strdel(&output);
		return (count);
	}
	ft_putchar(c);
	count = ft_strlen(output);
	ft_strdel(&str);
	ft_strdel(&output);
	return (count + 1);
}

int	c_converse(va_list args, t_modifiers *mods)
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
	{

	}
	output = treat_width(str, mods, ft_strlen(str), 0);
	ft_putstr(output);
	count = ft_strlen(output);
	ft_strdel(&str);
	ft_strdel(&output);
	return (count);
}
