/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/02 20:25:19 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_converse(va_list args, t_modifiers *mods)
{
	char	*string;
	int		count;
	char	*output;
	char	*temp;

	string = va_arg(args, char *);
	if (string == NULL)
		output = ft_strdup("(null)");
	else
		output = ft_strdup(string);
	if (mods->precision < 0)
		mods->precision = ft_strlen(output);
	if (mods->dot)
		temp = ft_strndup(output, mods->precision);
	else
		temp = ft_strdup(output);
	ft_strdel(&output);
	output = treat_width(temp, mods, ft_strlen(temp), 0);
	ft_strdel(&temp);
	temp = ft_strdup(output);
	ft_strdel(&output);
	count = ft_strlen(temp);
	ft_putstr(temp);
	ft_strdel(&temp);
	return (count);
}

int	o_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char				*string;
	int					count;
	char				*output;

	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 8);
	// output = ft_strdup(string);
	// ft_strdel(&string);
	if (mods->hash && mods->dot && mods->width >= mods->precision)
		mods->o_zero = 1;
	if (mods->hash == 1 && num && mods->precision < ft_strlen(string))
		output = ft_strjoin("0", string);
	else
		output = ft_strdup(string);
	ft_strdel(&string);
	string = treat_w_mods(output, mods, ft_strlen(output), num);
	ft_strdel(&output);
	output = check_edges(mods, string, num);
	ft_strdel(&string);
	ft_putstr(output);
	count = ft_strlen(output);
	ft_strdel(&output);
	//ft_strdel(&string);
	return (count);
}

int	x_converse(va_list args, t_modifiers *mods)
{
	unsigned long long		num;
	char					*string;
	char					*output;
	char					*temp;
	int						count;

	mods->plus = 0;
	num = va_arg(args, unsigned long long int );
	string = type_cast(num, mods, 16);
	count = ft_strlen(string);
	output = ft_strdup(string);
	ft_strdel(&string);
	string = treat_precision(output, mods, count, num);
	ft_strdel(&output);
	if (mods->precision || !mods->precision && mods->width)
		temp = treat_zerox(string, mods, num);
	else
		temp = ft_strdup(string);
	output = treat_width(temp, mods, ft_strlen(temp), num);
	ft_strdel(&temp);
	temp = check_edges(mods, output, num);
	ft_strdel(&string);
	string = treat_zerox(temp, mods, num);
	count = ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&temp);
	ft_strdel(&string);
	ft_strdel(&output);
	return (count);
}

int	p_converse(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;
	char			*output;
	int				count;

	num = va_arg(args, long long int );
	mods->p_spec++;
	string = ft_itoabase(num, 16, 1);
	if (!mods->precision)
	{
		output = ft_strjoin("0x", string);
		mods->hash = 2;
	}
	else
		output = ft_strdup(string);
	ft_strdel(&string);
	string = treat_w_mods(output, mods, ft_strlen(output), num);
	ft_strdel(&output);
	if(mods->hash == 2)
		output = ft_strdup(string);
	else
		output = ft_strjoin("0x", string);
	ft_strdel(&string);
	string = check_edges(mods, output, num);
	count = ft_strlen(output);
	ft_putstr(string);
	ft_strdel(&string);
	ft_strdel(&output);
	return (count);
}

int	f_converse(va_list args, t_modifiers *mods)
{
	long double		num;
	char			*string;
	int				count;
	char			*output;

	if (mods->ld == 1)
		num = (long double)va_arg(args, long double );
	else
		num = (double)va_arg(args, double );
	if (!mods->dot && mods->precision == 0)
		mods->precision = 6;
	if (mods->dot && !mods->hash && !mods->precision)
		mods->precision = -1;
	if (mods->zero)
		mods->dot = 0;
	string = ft_ftoa(num, mods->precision);
	// output = ft_strdup(string);
	// ft_strdel(&string);
	if (string[0] == '-')
	{
		mods->sign = 1;
		mods->plus = 0;
		if (mods->width && mods->dot && !mods->precision)
			mods->width--;
		mods->d_space = 0;
		if (mods->zero && mods->width && !mods->minus && !mods->dot || mods->precision)
		{
			mods->d_zerominus++;
			mods->width--;
		}
	}
	if (mods->zero)
	{
		mods->dot = 0;
		mods->precision = mods->width;
	}
	if (mods->space && !mods->plus && 1 / num > 0)
	{
		mods->d_space = 1;
		if (mods->precision)
			mods->precision--;
		if (mods->width)
			mods->width--;
	}
	if (mods->dot && mods->hash && !mods->precision)
		output = ft_strjoin(string + mods->d_zerominus, ".");
	else
		output = ft_strdup(string + mods->d_zerominus);
	ft_strdel(&string);
	if (mods->plus && mods->precision)
		mods->precision--;
	if (num == 1.0 / 0 || num == -1.0 / 0 || num != num)
	{
		mods->dot = 0;
		mods->zero = 0;
		mods->precision = 0;
		if (num == -1.0 / 0 && mods->width++)
			mods->sign++;
		ft_strdel(&output);
		string = check_infinity(num, mods);
		output = treat_width(string, mods, ft_strlen(string), num);
		count = ft_strlen(output);
		ft_putstr(output);
		ft_strdel(&string);
		ft_strdel(&output);
		return (count);
	}
	string = treat_w_mods(output, mods, ft_strlen(output), num);
	ft_putstr(string);
	count = ft_strlen(string);
	ft_strdel(&string);
	ft_strdel(&output);
	return (count);
}

int	u_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char				*string;
	char				*output;
	int					count;

	if (mods->capital)
		mods->cap_u = 1;
	mods->hash = 0;
	num = va_arg(args, unsigned long long );
	mods->plus = 0;
	string = type_cast(num, mods, 10);
	output = treat_w_mods(string, mods, ft_strlen(string), num);
	ft_strdel(&string);
	string = check_edges(mods, output, num);
	ft_putstr(string);
	count = ft_strlen(string);
	ft_strdel(&string);
	ft_strdel(&output);
	return (count);
}

int per_converse(va_list args, t_modifiers *mods)
{
	int		count;
	char	*res;
	char	*temp;
	int		i;
	char	c;

	c = ' ';
	i = 0;
	count = 0;
	(void)args;
	//res = ft_strnew(1 + mods->width);
	res = ft_strdup("%");
	//res[0] = '%';
	// if (mods->zero && !mods->minus)
	// 	c = '0';
	// while (mods->width && i < mods->width - 1)
	// 	res[i++] = c;
	// if (mods->width && !mods->minus)
	// 	temp = ft_strjoin(res, "%");
	// else if (mods->minus)
	// 	temp = ft_strjoin("%", res);
	// else
	// 	temp = ft_strdup(res);
	temp = treat_width(res, mods, ft_strlen(res), count);
	count = ft_strlen(temp);
	ft_putstr(temp);
	ft_strdel(&res);
	ft_strdel(&temp);
	return (count);
}
