/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:00:58 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/08 21:50:01 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_mods(t_modifiers *mods)
{
	mods->zero = 0;
	mods->precision = 0;
	mods->hash = 0;
}

int	b_specifier(va_list args, t_modifiers *mods)
{
	char		*str;
	char		*output;
	int			count;
	long long	num;

	set_mods(mods);
	num = va_arg(args, long long);
	if (mods->l == 2)
		str = ft_dectobin((long long)num);
	else if (mods->l == 1)
		str = ft_dectobin((long)num);
	else
		str = ft_dectobin((int)num);
	count = 0;
	output = treat_mods(str, mods, ft_strlen(str), num);
	count = ft_putstrlen(output);
	ft_strdel(&output);
	ft_strdel(&str);
	return (count);
}
