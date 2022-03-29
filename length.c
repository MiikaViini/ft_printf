/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/28 13:31:00 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*l_length(va_list args, char *format, t_modifiers *mods)
{
	(void)args;
	if (*format == 'l')
	{
		mods->l += 1;
		format++;
	}

	return (format);
}

char	*h_length(va_list args, char *format, t_modifiers *mods)
{
	(void)args;
	if (*format == 'h')
	{
		mods->h += 1;
		format++;
	}

	return (format);
}

char	*ld_length(va_list args, char *format, t_modifiers *mods)
{
	(void)args;
	if (*format == 'L')
	{
		mods->ld = 1;
		format++;
	}

	return (format);
}

char	*type_cast(unsigned long long int num, t_modifiers *mods, int base)
{
	char	*string;

	string = NULL;
	
	if (mods->h == 1)
		string = ft_itoabase((unsigned short)num, base, mods->cap_x);
	else if (mods->h == 2)
		string = ft_itoabase((unsigned char)num, base, mods->cap_x);
	else if (mods->l == 1)
		string = ft_itoabase((unsigned long)num, base, mods->cap_x);
	else if (mods->l == 2)
		string = ft_itoabase((unsigned long long)num, base, mods->cap_x);
	else
		string = ft_itoabase((unsigned int)num, base, mods->cap_x);
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
		string = ft_ltoa((long)num);
	else if (mods->l == 2)
		string = ft_ltoa((long long)num);
	else
		string = ft_ltoa((int)num);
	return (string);
}


