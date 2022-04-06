/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_with_mods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/04 20:38:25 by mviinika         ###   ########.fr       */
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
	while (length < mods->precision)
	{
		res[i++] = '0';
		mods->precision--;
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
	temp = ft_strcpy(temp, fill);
	string = ft_strjoin(temp, string);
	ft_strdel(&temp);
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
	res = ft_strdup(string);
	if (mods->width == 0 || count < 0 || mods->width <= mods->precision)
		return (string);
	temp = ft_strnew(count);
	//printf("1f%sf", string);
	if (mods->zero == 1 && mods->minus == 0)
		c = '0';
	while (count-- > 0 && i < mods->width - (int)ft_strlen(string))
		temp[i++] = c;
	//printf("%d", i);
	//printf("2f%sf", string);
	if (mods->minus == 1)
		res = ft_strjoin(res, temp);
	else if ((mods->minus == 0 && mods->zero == 1 && num < 0) || (mods->plus && mods->precision > mods->width))
		res = is_num_neg(res, temp, mods);
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

	res = str;
	if (mods->plus == 1 && mods->width && !mods->dot)
	{
		count++;
		res = ft_strjoin("+", str);
	}
	res = treat_precision(res, mods, count);
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
