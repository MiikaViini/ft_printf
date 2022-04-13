/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/13 07:47:56 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_converse(va_list args, t_modifiers *mods)
{
	char	*string;
	int		count;
	char	*output;

	if (mods->star)
		mods->width = va_arg(args, int );
	string = va_arg(args, char *);
	if (string == NULL)
		string = ft_strdup("(null)");
	count = ft_strlen(string);
	if (mods->dot)
		output = ft_strndup(string, mods->precision);
	else
		output = ft_strdup(string);
	string = treat_width(output, mods, ft_strlen(output), count);
	ft_putstr(string);
	count = ft_strlen(string);
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
		if (mods->zero && mods->width && !mods->minus || mods->precision)
		{
			string++;
			mods->width--;
		}
	}
	if (mods->minus)
		mods->zero = 0;
		//output = ft_strdup(string + mods->sign);
	output = ft_strdup(string);
	count = ft_strlen(string);
	string = treat_w_mods(output, mods, count, num);
	output = check_edges(mods, string, num);
	ft_putstr(output);
	count = ft_strlen(output);
	free(string);
	return (count);
}

int	c_converse(va_list args, t_modifiers *mods)
{
	char	*str;
	int		c;

	str = ft_strnew(mods->width);
	c = va_arg(args, int );
	if (!c)
	{
		str = treat_width(str, mods, ft_strlen(str), c);
		if (mods->minus)
		{
			ft_putchar(c);
			ft_putstr(str + 1);
			return (ft_strlen(str));
		}
		else if (mods->width)
		{
			ft_putstr(str + 1);
			ft_putchar(c);
			return (ft_strlen(str));
		}
		ft_putchar(c);
		return (1);
	}
	str[0] = c;
	str = treat_width(str, mods, ft_strlen(str), c);
	ft_putstr(str);
	return (ft_strlen(str));
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
	if (mods->hash == 1)
		output = ft_strjoin("0", string);
	if (mods->hash && mods->dot && !mods->width)
		mods->o_zero = 1;
	string = treat_w_mods(output, mods, ft_strlen(string), num);
	output = ft_strdup(string);
	string = check_edges(mods, output, num);
	count = ft_strlen(string);
	ft_putstr(string);
	//free(string);
	return (count);
}

int	x_converse(va_list args, t_modifiers *mods)
{
	unsigned long long		num;
	char					*string;
	char					*output;
	int						count;

	num = va_arg(args, unsigned long long int );
	string = type_cast(num, mods, 16);
	string = treat_zerox(string, mods, num);
	output = ft_strdup(string);
	string = treat_width(output, mods, ft_strlen(string), num);
	output = ft_strdup(string);
	string = check_edges(mods, output, num);
	count = ft_strlen(string);
	ft_putstr(string);
	ft_strdel(&output);
	return (count);
}

int	p_converse(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;
	char			*output;
	int				count;

	(void)mods;
	num = va_arg(args, long long int );
	string = ft_itoabase(num, 16, 1);
	output = ft_strjoin("0x", string);
	count = ft_strlen(output);
	if (count < mods->width)
		output = treat_width(output, mods, count, num);
	ft_putstr(check_edges(mods, output, num));
	free(output);
	free(string);
	return (ft_strlen(string));
}

int	f_converse(va_list args, t_modifiers *mods)
{
	long double		num;
	char			*string;
	int				count;
	//char			*output;

	if (mods->ld == 1)
		num = va_arg(args, long double );
	else
		num = va_arg(args, double );
	if (mods->dot == 0 && mods->precision == 0)
		mods->precision = 6;
	string = ft_ftoa(num, mods->precision);
	count = ft_strlen(string);
	if (num == 1.0 / 0 || num == -1.0 / 0 || num != num)
	{
		ft_putstr(check_infinity(num));
		return (ft_strlen(check_infinity(num)));
	}
	if (mods->plus == 1)
		string = ft_strjoin("+", string);
	if (mods->space && !mods->plus)
		string = ft_strjoin(" ", string);
	if (count < mods->width)
		string = treat_width(string, mods, count + mods->plus + mods->space, num);
	ft_putstr(string);
	//free(string);
	return (ft_strlen(string));
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
	ft_putstr(check_edges(mods, string, num));

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
