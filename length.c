/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 21:13:01 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_length(char *format, t_modifiers *modifiers)
{
	if (*format == 'l')
		modifiers->l += 1;
	// if (*format == 'l')
	// 	modifiers->l = 2;
}

void	h_length(char *format, t_modifiers *modifiers)
{
	if (*format == 'h')
		modifiers->h += 1;
	// if (*format == 'h')
	// 	modifiers->h = 2;
}

char	*type_cast(unsigned long long int num, t_modifiers *mods, int base)
{
	char	*string;

	string = NULL;
	if (mods->h == 1)
		string = ft_itoabase((unsigned short)num, base, 1);
	else if (mods->h == 2)
		string = ft_itoabase((unsigned char)num, base, 1);
	else if (mods->l == 1)
		string = ft_itoabase((unsigned long)num, base, 1);
	else if (mods->l == 2)
		string = ft_itoabase((unsigned long long)num, base, 1);
	else
		string = ft_itoabase((unsigned int)num, base, 1);
	return (string);
}

char	*type_cast_int(long long int num, t_modifiers *mods)
{
	char	*string;

	string = NULL;
	if (mods->h == 1)
		string = ft_itoa((short)num);
	else if (mods->h == 2)
		string = ft_itoa((char)num);
	else if (mods->l == 1)
		string = ft_itoa((long)num);
	else if (mods->l == 2)
		string = ft_itoa((long long)num);
	else
		string = ft_itoa((int)num);
	return (string);
}
