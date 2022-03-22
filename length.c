/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 11:08:56 by mviinika         ###   ########.fr       */
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

long long int	cast_long(long long int num, t_modifiers *mods)
{
	if (mods->l == 1)
		return ((long int)num);
	else if (mods->l == 2)
		return (num);
	else if (mods->h == 1)
		return ((short int)num);
	else if (mods->h== 2)
		return ((char)num);
	return ((int)num);
}
