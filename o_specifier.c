/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:41:11 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/08 18:59:08 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	o_specifier(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char				*string;
	int					count;
	char				*output;

	mods->plus = 0;
	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 8);
	if (mods->hash && mods->dot && mods->width >= mods->precision)
		mods->o_zero = 1;
	if (mods->hash == 1 && num && mods->precision < (int)ft_strlen(string)
		&& string[0] != '0')
		output = ft_strjoin("0", string);
	else
		output = ft_strdup(string);
	ft_strdel(&string);
	string = check_edges(mods, output, num);
	ft_strdel(&output);
	output = treat_mods(string, mods, ft_strlen(string), num);
	ft_strdel(&string);
	count = ft_putstrlen(output);
	ft_strdel(&output);
	return (count);
}
