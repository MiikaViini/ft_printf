/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:37:09 by mviinika          #+#    #+#             */
/*   Updated: 2022/05/03 22:07:58 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*apply_prefix(char *string, t_modifiers *mods)
{
	char	*res;

	if (!mods->precision && mods->hash != 2)
	{
		res = ft_strjoin("0x", string);
		mods->hash = 2;
	}
	else
		res = ft_strdup(string);
	return (res);
}

int	p_specifier(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;
	char			*output;
	int				count;

	num = va_arg(args, long long );
	mods->p_spec++;
	mods->precision = 0;
	mods->dot = 0;
	string = ft_itoabase(num, 16, 1);
	output = apply_prefix(string, mods);
	ft_strdel(&string);
	string = treat_w_mods(output, mods, ft_strlen(output), num);
	ft_strdel(&output);
	output = apply_prefix(string, mods);
	ft_strdel(&string);
	string = check_edges(mods, output, num);
	count = ft_strlen(output);
	ft_putstr(string);
	ft_strdel(&string);
	ft_strdel(&output);
	return (count);
}
