/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/03 22:05:01 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	f_neg_mods(t_modifiers *mods)
{
	mods->sign = 1;
	mods->plus = 0;
	if (mods->width && mods->dot && !mods->precision)
		mods->width--;
	mods->d_space = 0;
	if (mods->zero && mods->width && !mods->minus && !mods->dot
		|| mods->precision)
	{
		mods->d_zerominus++;
		mods->width--;
	}
}

static void	f_prep_mods(t_modifiers *mods, char *string, long double num)
{
	if (*string == '-')
		f_neg_mods(mods);
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
	if (mods->plus && mods->precision)
		mods->precision--;
}

static int	inf_and_nan(t_modifiers *mods, int count, double num)
{
	char	*string;
	char	*output;

	mods->dot = 0;
	mods->zero = 0;
	mods->precision = 0;
	if (num == -1.0 / 0 && mods->width++)
		mods->sign++;
	string = check_infinity(num, mods);
	output = treat_width(string, mods, ft_strlen(string));
	count = ft_putstrlen(output);
	ft_strdel(&string);
	ft_strdel(&output);
	return (count);
}

static void	f_prec_prep(t_modifiers *mods)
{
	if (!mods->dot && mods->precision == 0)
		mods->precision = 6;
	if (mods->dot && !mods->hash && !mods->precision)
		mods->precision = -1;
}

int	f_specifier(va_list args, t_modifiers *mods)
{
	long double		num;
	char			*string;
	int				count;
	char			*output;

	if (mods->ld == 1)
		num = (long double)va_arg(args, long double );
	else
		num = (double)va_arg(args, double );
	count = 0;
	f_prec_prep(mods);
	string = ft_ftoa(num, mods->precision);
	f_prep_mods(mods, string, num);
	if (num == 1.0 / 0 || num == -1.0 / 0 || num != num)
		return (inf_and_nan(mods, count, num));
	if (mods->dot && mods->hash && !mods->precision)
		output = ft_strjoin(string + mods->d_zerominus, ".");
	else
		output = ft_strdup(string + mods->d_zerominus);
	ft_strdel(&string);
	string = treat_w_mods(output, mods, ft_strlen(output), num);
	count = ft_putstrlen(string);
	ft_strdel(&string);
	ft_strdel(&output);
	return (count);
}

// if (string[0] == '-')
	// {
	// 	mods->sign = 1;
	// 	mods->plus = 0;
	// 	if (mods->width && mods->dot && !mods->precision)
	// 		mods->width--;
	// 	mods->d_space = 0;
	// 	if (mods->zero && mods->width && !mods->minus && !mods->dot || mods->precision)
	// 	{
	// 		mods->d_zerominus++;
	// 		mods->width--;
	// 	}
	// }
	// if (mods->zero)
	// {
	// 	mods->dot = 0;
	// 	mods->precision = mods->width;
	// }
	// if (mods->space && !mods->plus && 1 / num > 0)
	// {
	// 	mods->d_space = 1;
	// 	if (mods->precision)
	// 		mods->precision--;
	// 	if (mods->width)
	// 		mods->width--;
	// }


			// mods->dot = 0;
		// mods->zero = 0;
		// mods->precision = 0;
		// if (num == -1.0 / 0 && mods->width++)
		// 	mods->sign++;
		// ft_strdel(&output);
		// string = check_infinity(num, mods);
		// output = treat_width(string, mods, ft_strlen(string), num);
		// count = ft_strlen(output);
		// ft_putstr(output);
		// ft_strdel(&string);
		// ft_strdel(&output);
		// return (count);
