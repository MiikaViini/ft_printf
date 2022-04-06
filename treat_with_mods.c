/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_with_mods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/06 15:50:27 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_precision(char *string, t_modifiers *mods, int length, int num)
{
	char	*res;
	char	*temp;
	int		i;

	i = 0;
	if (mods->dot == 0 && !mods->plus)
		return (string);
	res = ft_strnew(mods->precision + 1);
	if (mods->plus && string[i] != '+'&& num >= 0)
	{
		res[i++] = '+';
	}
	if (string[i] != '-' && num < 0)
	{
		res[i++] = '-';
	}
	while (length < mods->precision)
	{	
		res[i++] = '0';
		mods->precision--;
	}
	temp = ft_strjoin(res, string);
	free(res);
	return (temp);
}

char	*is_num_neg(char *string, char *fill, t_modifiers *mods, int num)
{
	int		i;
	char	*temp;
	int		sign;

	i = 0;
	sign = 0;
	temp = ft_strnew(ft_strlen(fill) + 1);
	if (mods->plus && !mods->dot && num > 0)
	{
		temp[0] = '+';
		temp++;
		sign++;
	}
	else if (mods->width && num < 0)
	{
		temp[0] = '-';
		temp++;
		sign++;
	}
	while (string[i] && sign)
	{
		string[i] = string[i + 1];
		i++;
	}
	temp = ft_strcpy(temp, fill);
	string = ft_strjoin(temp - sign, string);
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
	(void)num;
	res = ft_strdup(string);
	if (mods->width == 0 || count < 0 || mods->width <= mods->precision)
		return (string);
	temp = ft_strnew(count);
	if (mods->zero == 1 && mods->minus == 0)
		c = '0';
	while (count-- > 0 && i < mods->width - (int)ft_strlen(string))
		temp[i++] = c;
	if (mods->minus == 1)
		res = ft_strjoin(res, temp);
	else if ((mods->minus == 0 && mods->zero == 1) || (mods->plus && mods->precision > mods->width))
		res = is_num_neg(res, temp, mods, num);
	else
		res = ft_strjoin(temp, res);
	// ft_strdel(&temp);
	// temp = res;
	// ft_strdel(&res);
	return (res);
}

char	*treat_w_mods(char *str, t_modifiers *mods, int count, int num)
{
	char	*res;

	res = ft_strdup(str);
	if (mods->d_space > 0 && num > 0 && !mods->width)
	{
		count++;
		res = ft_strjoin(" ", str);
	}
	// if ((mods->d_space <= 0 && mods->plus && num >= 0) || (mods->plus == 1 && mods->width && !mods->dot && num >= 0 && mods->precision > (int)ft_strlen(str)))
	// {
	// 	count++;
	// 	res = ft_strjoin("+", str);
	// }
	res = treat_precision(res, mods, count, num);
	if (count < mods->width)
		res = treat_width(res, mods, ft_strlen(res), num);
	return (res);
}
char	*treat_zerox(char *string, t_modifiers *mods, int num)
{
	char	*res;

	res = ft_strdup(string);
	if ((mods->hash == 1 && mods->cap_x == 1 && num && !mods->zero) || (mods->minus && mods->hash == 1))
		res = ft_strjoin("0x", string);
	else if ((mods->hash == 1 && mods->cap_x == 0 && num && !mods->zero)|| (mods->minus && mods->hash == 1))
		res = ft_strjoin("0X", string);
	string = res;
	ft_strdel(&res);
	return (string);
}
