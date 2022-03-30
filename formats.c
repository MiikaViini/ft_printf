/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/30 21:55:48 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_converse(va_list args, t_modifiers *mods)
{
	char	*string;
	int		count;
	char	*output;

	string = va_arg(args, char *);
	output = string;
	count = ft_strlen(string);
	if (mods->precision < count)
		output = ft_strndup(string, mods->precision);
	output = ft_strdup(string);
	output = treat_width(output, mods, ft_strlen(output));
	ft_putstr(output);
	free(output);
	return (count);
}

int	d_converse(va_list args, t_modifiers *mods)
{
	long long		num;
	int				count;
	char			*string;

	num = va_arg(args, long long );
	string = type_cast_int(num, mods);
	count = ft_strlen(string);
	if (count < mods->width)
		string = treat_width(string, mods, count);
	if (mods->plus == 1 && num > 0)
		string = ft_strjoin("+", string);
	string = treat_precision(string, mods, count);
	ft_putstr(check_edges(mods, string, num));
	free(string);
	return (count);
}

int	c_converse(va_list args, t_modifiers *mods)
{
	int	c;
	(void)mods;
	c = va_arg(args, int );
	ft_putchar(c);
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
	output = string;
	if (mods->hash == 1)
		output = ft_strjoin("0", string);
	count = ft_strlen(output);
	if (count < mods->width)
		output = treat_width(string, mods, count);
	output = treat_precision(output, mods, count);
	ft_putstr(check_edges(mods, output, num));
	free(string);
	return (count);
}

int	x_converse(va_list args, t_modifiers *mods)
{
	unsigned long long		num;
	char					*string;
	int						count;
	char					*output;

	num = va_arg(args, unsigned long long int );
	string = type_cast(num, mods, 16);
	output = string;
	if (mods->hash == 1 && mods->cap_x == 1)
		output = ft_strjoin("0x", string);
	else if (mods->hash == 1 && mods->cap_x == 0)
		output = ft_strjoin("0X", string);
	count = ft_strlen(string);
	if (count < mods->width)
		output = treat_width(string, mods, count);
	output = treat_precision(output, mods, count);
	ft_putstr(check_edges(mods, output, num));
	count = ft_strlen(string);
	free(string);
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
		output = treat_width(output, mods, count);
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
	if (count < mods->width)
		string = treat_width(string, mods, count);
	ft_putstr(string);
	free(string);
	return (count);
}

int	u_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char				*string;
	int					count;

	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 10);
	count = ft_strlen(string);
	if (count < mods->width)
		string = treat_width(string, mods, count);
	string = treat_precision(string, mods, count);
	ft_putstr(check_edges(mods, string, num));
	free(string);
	return (count);
}

int per_converse(va_list args, t_modifiers *mods)
{
	int	count;

	(void)mods;
	(void)args;
	count = 0;
	ft_putchar('%');
	return(1);
}
