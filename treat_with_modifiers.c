/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_with_modifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/31 15:45:20 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_precision(char *string, t_modifiers *mods, int length)
{
	char	*res;
	char	*temp;
	int		i;

	i = 0;
	if (mods->dot == 0)
		return (string);
	res = ft_strnew(mods->precision + 1);
	if (mods->plus)
			res[i++] = '+';
	//printf("%d", mods->plus);
	while (length < mods->precision--)
	{
		res[i++] = '0';
		//mods->precision--;
	}
	temp = ft_strjoin(res, string);
	free(res);
	return (temp);
}

char	*is_num_neg(char *string, char *fill, t_modifiers *mods)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strnew(ft_strlen(fill) + 1);
	if (mods->plus && !mods->dot)
	{
		temp[0] = '+';
		temp++;
	}
	else if (!mods->width)
	{
		temp[0] = '-';
		temp++;
	}
	while (string[i])
	{
		string[i] = string[i + 1];
		i++;
	}
	temp = ft_strcpy((temp), fill);
	string = ft_strjoin(temp, string);
	//free(temp);
	return (string);
}

char	*treat_width(char *string, t_modifiers *mods, int length, int num)
{
	char	*temp;
	char	*res;
	int		i;
	int		count;
	char	c;

	c = ' ';
	count = mods->width - length;
	i = 0;
	if (mods->width == 0 || count < 0 || mods->width <= mods->precision)
		return (string);
	temp = ft_strnew(count);
	if (mods->zero == 1 && mods->minus == 0)
		c = '0';
	while (count-- > 0 && i < mods->width - mods->precision)
		temp[i++] = c;
	if (mods->minus == 1)
		res = ft_strjoin(string, temp);
	else if ((mods->minus == 0 && mods->zero == 1 && num < 0) || mods->plus)
		res = is_num_neg(string, temp, mods);
	else
		res = ft_strjoin(temp, string);
	free(temp);
	return (res);
}

char	*treat_w_mods(char *str, t_modifiers *mods, int count, int num)
{
	char	*res;

	res = str;
	if (mods->plus == 1 && !mods->width)
	{
		count++;
		res = ft_strjoin("+", str);
	}
	res = treat_precision(res, mods, count);
	if (count < mods->width)
		res = treat_width(res, mods, ft_strlen(res), num);
	return (res);
}
