/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/26 12:07:46 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_converse(va_list args, t_modifiers *mods)
{
	char	*string;
	int		count;
	char	*output;

	string = va_arg(args, char *);
	if (string == NULL)
		string = ft_strdup("(null)");
	if (mods->dot)
		output = ft_strndup(string, mods->precision);
	else
		output = ft_strdup(string);
	string = treat_width(output, mods, ft_strlen(output), count);
	ft_strdel(&output);
	output = ft_strdup(string);
	ft_strdel(&string);
	count = ft_strlen(output);
	ft_putstr(output);
	ft_strdel(&output);
	return (count);
}

int	d_converse(va_list args, t_modifiers *mods)
{
	long long		num;
	int				count;
	char			*string;
	char			*output;

	mods->d_space = mods->space - mods->plus;
	num = va_arg(args, long long );
	string = type_cast_int(num, mods);
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
	if (mods->minus)
		mods->zero = 0;
	string = treat_w_mods(string + mods->d_zerominus, mods, ft_strlen(string) - mods->d_zerominus, num);
	output = ft_strdup(string);
	ft_strdel(&string);
	string = check_edges(mods, output, num);
	ft_putstr(string);
	count = ft_strlen(string);
	ft_strdel(&output);
	return (count);
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
	output = ft_strdup(str);
	ft_strdel(&str);
	if (!c)
	{
		str = treat_width(output, mods, ft_strlen(output), c);
		if (mods->minus)
		{
			ft_putchar(c);
			ft_putstr(str + 1);
			count = ft_strlen(str);
			ft_strdel(&str);
			ft_strdel(&output);
			return (count);
		}
		else if (mods->width)
		{
			ft_putstr(str + 1);
			ft_putchar(c);
			count = ft_strlen(str);
			ft_strdel(&str);
			ft_strdel(&output);
			return (count);
		}
		ft_putchar(c);
		ft_strdel(&str);
		ft_strdel(&output);
		return (1);
	}
	*output = c;
	ft_strdel(&str);
	str = treat_width(output, mods, ft_strlen(output), c);
	ft_putstr(str);
	count = ft_strlen(str);
	ft_strdel(&str);
	ft_strdel(&output);
	return (1);
}

int	o_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char				*string;
	int					count;
	char				*output;

	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 8);
	output = ft_strdup(string);
	if (mods->hash && mods->dot && mods->width >= mods->precision)
		mods->o_zero = 1;
	if (mods->hash == 1 && num && mods->precision < ft_strlen(output))
		output = ft_strjoin("0", string);
	ft_strdel(&string);
	string = treat_w_mods(output, mods, ft_strlen(output), num);
	string = check_edges(mods, string, num);
	count = ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&string);
	return (count);
}

int	x_converse(va_list args, t_modifiers *mods)
{
	unsigned long long		num;
	char					*string;
	char					*output;
	char					*temp;
	int						count;

	num = va_arg(args, unsigned long long int );
	string = type_cast(num, mods, 16);
	count = ft_strlen(string);
	if (!mods->precision)
		temp = treat_zerox(string, mods, num);
	else
		temp = ft_strdup(string);
	ft_strdel(&string);
	temp = treat_w_mods(temp, mods, count, num);
	output = ft_strdup(temp);
	ft_strdel(&temp);
	temp = check_edges(mods, output, num);
	if (mods->precision)
		string = treat_zerox(temp, mods, num);
	else
		string = ft_strdup(temp);
	count = ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&temp);
	ft_strdel(&string);
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
	output = ft_strdup(string);
	string = ft_strjoin("0x", output);
	output = treat_w_mods(string, mods, ft_strlen(output), num);

	count = ft_strlen(output);
	//output = check_edges(mods, output, num);
	// ft_strdel(&string);
	ft_putstr(output);

	return (ft_strlen(output));
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
	output = ft_strdup(string);
	ft_strdel(&string);
	if (output[0] == '-')
	{
		mods->sign = 1;
		mods->plus = 0;
		if (mods->width && mods->dot && !mods->precision)
			mods->width--;
		mods->d_space = 0;
		if (mods->zero && mods->width && !mods->minus && !mods->dot || mods->precision)
		{
			output++;
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
	}
	if (mods->dot && mods->hash && !mods->precision)
		output = ft_strjoin(output, ".");
	if (mods->plus)
		mods->precision--;
	count = ft_strlen(output);
	//string = ft_strdup(output);
	if (num == 1.0 / 0 || num == -1.0 / 0 || num != num)
	{
		mods->dot = 0;
		mods->zero = 0;
		mods->precision = 0;
		if (num == -1.0 / 0  && mods->width++)
			mods->sign++;
		output = check_infinity(num, mods);
		output = treat_width(output, mods, ft_strlen(output), num);
		ft_putstr(output);
		return (ft_strlen(output));
	}
	output = treat_w_mods(output, mods, ft_strlen(output), num);
	ft_putstr(output);
	//free(string);
	return (ft_strlen(output));
}

int	u_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char				*string;

	if (mods->capital)
		mods->cap_u = 1;
	num = va_arg(args, unsigned long long );
	mods->plus = 0;
	string = type_cast(num, mods, 10);

	// if (count < mods->width)
	// 	string = treat_width(string, mods, count, num);
	// string = treat_precision(string, mods, count);
	string = treat_w_mods(string, mods, ft_strlen(string), num);
	string = check_edges(mods, string, num);
	ft_putstr(string);

	//free(string);
	return (ft_strlen(string));
}

int per_converse(va_list args, t_modifiers *mods)
{
	int		count;
	char	*res;
	int		i;
	char	c;

	c = ' ';
	i = 0;
	count = 0;
	(void)args;
	res = ft_strnew(1 + mods->width);
	if (mods->zero && !mods->minus)
		c = '0';
	if (!mods->width)
	{
		ft_putchar('%');
		return(1);
	}
	while (mods->width && i < mods->width - 1)
		res[i++] = c;
	if (mods->width && !mods->minus)
		res = ft_strjoin(res, "%");
	else if (mods->minus)
		res = ft_strjoin("%", res);
	ft_putstr(res);
	return(ft_strlen(res));
}
