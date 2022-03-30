/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_with_modifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/30 13:56:39 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_precision(char *string, t_modifiers *mods, int length)
{
	char	*res;
	int		i;

	i = 0;
	if (mods->dot == 0)
		return (string);
	res = ft_strnew(mods->precision);
	while (length < mods->precision)
	{
		res[i++] = '0';
		mods->precision--;
	}
	return (ft_strjoin(res, string));
}

char	*treat_width(char *string, t_modifiers *mods, int length)
{
	char	*temp;
	char	*res;
	int		i;
	int		count;

	count = mods->width - length;
	i = 0;
	if (mods->width == 0 || count < 0 || mods->width <= mods->precision)
		return (string);
	temp = ft_strnew(count);
	while (count > 0 && i < mods->width - mods->precision)
	{
		temp[i++] = ' ';
		count--;
		//mods->width--;
	}
	if (mods->minus == 1)
		res = ft_strjoin(string, temp);
	else
		res = ft_strjoin(temp, string);
	free(temp);
	return (res);
}