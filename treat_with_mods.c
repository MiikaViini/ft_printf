/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_with_mods.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/25 21:34:14 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_precision(char *string, t_modifiers *mods, int length, long long num)
{
	char	*res;
	int		i;

	i = 0;
	//temp = ft_strdup(string);
	if (!mods->precision && !mods->plus)
		return (string);
	res = ft_strnew(mods->precision + 1);
	while (length + mods->sign < mods->precision + mods->sign)
	{
		res[i++] = '0';
		mods->precision--;
	}
	if (mods->plus && num >= 0 && *res == '0')
	{
		string = ft_strjoin("+", res);
		ft_strdel(&res);
		res = ft_strdup(string);
		ft_strdel(&string);
	}
	else if (mods->sign && *string != '-')
	{
		string = ft_strjoin("-", res);
		ft_strdel(&res);
		res = ft_strdup(string);
		ft_strdel(&string);
	}
	//string = ft_strjoin(res, temp);
	//ft_strdel(&res);
	//res = ft_strdup(string);
	//ft_strdel(&temp);
	//ft_strdel(&string);
	return (res);
}

// char	*is_num_neg(char *string, char *fill, t_modifiers *mods, long long num)
// {
// 	int		i;
// 	char	*temp;
// 	int		sign;

// 	i = 0;
// 	sign = 0;
// 	temp = ft_strnew(ft_strlen(fill) + 1);
// 	// if (mods->plus && !mods->dot && num > 0)
// 	// {
// 	// 	temp[0] = '+';
// 	// 	temp++;
// 	// 	sign++;
// 	// }
// 	// else if (mods->sign)
// 	// {
// 	// 	temp[0] = '-';
// 	// 	temp++;
// 	// 	sign++;
// 	// }
// 	while (string[i] && sign)
// 	{
// 		string[i] = string[i + 1];
// 		i++;
// 		// printf("[%s]\n", string);
// 		// exit(1);
// 	}
// 	temp = ft_strcpy(temp, fill);
// 	string = ft_strjoin(temp - sign, string);

// 	return (string);
// }

char	*treat_width(char *string, t_modifiers *mods, int length, long long num)
{
	char	*temp;
	char	*res;
	int		i;
	int		count;
	char	c;

	c = ' ';
	count = mods->width - length + (mods->dot * mods->sign);
	i = 0;
	(void)num;
	if (mods->width == 0 || count < 0)
		return (string);
	// res = ft_strdup(string);
	//
	temp = ft_strnew(count);
	if (mods->zero == 1 && mods->minus == 0 && !mods->dot || mods->zero == 1 && mods->minus == 0 && mods->precision < 0)
		c = '0';
	while (count-- > 0 && i < mods->width - (int)ft_strlen(string) - (mods->zero * mods->plus - mods->sign))
		temp[i++] = c;
	if (mods->minus == 1)
		res = ft_strjoin(string, temp);
	else
		res = ft_strjoin(temp, string);
	ft_strdel(&temp);
	temp = ft_strdup(res);
	ft_strdel(&res);
	return (temp);
}

char	*treat_w_mods(char *str, t_modifiers *mods, int count, long long num)
{
	char	*res;
	char	*temp;

	// res = ft_strdup(str);
	//ft_strdel(&str);
	temp = NULL;
	res = NULL;
	if (!mods->width && !mods->precision)
		return (str);
	temp = treat_precision(str, mods, ft_strlen(str), num);
	if (mods->d_space > 0 && !mods->zero)
	{
		res = ft_strjoin(" ", temp);
		ft_strdel(&temp);
		temp = ft_strdup(res);
		ft_strdel(&res);
	}
	if (count < mods->width + mods->sign)
	{
		res = treat_width(temp, mods, ft_strlen(temp), num);
		ft_strdel(&temp);
		temp = ft_strdup(res);
		ft_strdel(&res);
	}
	if (mods->d_space > 0 && mods->zero)
	{
		if (*str == '0' && mods->width)
			str++;
		res = ft_strjoin(" ", str);
	}
	// ft_stdel(&str);
	res = ft_strdup(str);
	ft_strdel(&str);
	res = apply_sign(res, mods, num);

	// printf("%s", str);
	// ;
	str = ft_strdup(res);


	ft_strdel(&res);
	return (str);
}

char	*treat_zerox(char *string, t_modifiers *mods, long long num)
{
	char	*res;

	res = ft_strdup(string);
	// if (res == NULL)
	// 	return (NULL);
	if ((mods->hash == 1 && mods->capital == 1
			&& num && !mods->zero) || (mods->minus && mods->hash == 1 && num && mods->capital == 1))
		res = ft_strjoin("0x", string);
	else if ((mods->hash == 1 && mods->capital == 0
			&& num && !mods->zero) || (mods->minus && mods->hash == 1 && num))
		res = ft_strjoin("0X", string);
	string = res;
	ft_strdel(&res);
	return (string);
}

char	*apply_sign(char *string, t_modifiers *mods, long long num)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strdup(string);
	if (num >= 0 && *string != ' ' && *string != '+' && mods->plus)
	{
		res = ft_strjoin("+", string);
	}

	else if ((mods->sign && *string == '0') || (mods->width <= ft_strlen(string) && mods->sign) && *string != '-' && *string != ' ')
	{
		res = ft_strjoin("-", string);
	}

	// else
	// 	return();
	//string = ft_strdup(res);
	//ft_strdel(&res);
	return (res);
}
