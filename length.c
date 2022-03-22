/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 14:52:36 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_length(char *format, t_modifiers *modifiers)
{
	if (*format++ == 'l')
		modifiers->l = 1;
	if (*format == 'l')
		modifiers->l = 2;
}

void	h_length(char *format, t_modifiers *modifiers)
{
	if (*format++ == 'h')
		modifiers->h = 1;
	if (*format == 'h')
		modifiers->h = 2;
}

void	*cast_long(long long int num, t_modifiers *mods, va_list args)
{
	if (mods->l == 1)
		num = va_arg(args, unsigned long int );
	else if (mods->l == 2)
		num = va_arg(args, long long );
	else if (mods->h == 1)
		num = va_arg(args, unsigned int );
	else if (mods->h == 2)
		return ((short *)num);
	else if (mods->h == 0 && mods->l == 0)
		num = va_arg(args, unsigned int );
	return ((short *)num);
}
