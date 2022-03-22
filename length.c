/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 15:10:41 by mviinika         ###   ########.fr       */
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

char	*type_cast(unsigned long long int num, t_modifiers *mods)
{
	char	*string;

	if (mods->h == 1)
		string = ft_itoabase((short)num, 16, 1);
	else if (mods->h == 2)
		string = ft_itoabase((char)num, 16, 1);
	else if (mods->l == 1)
		string = ft_itoabase((unsigned long)num, 16, 1);
	else if (mods->l == 2)
		string = ft_itoabase((unsigned long long)num, 16, 1);
	return (string);
}
