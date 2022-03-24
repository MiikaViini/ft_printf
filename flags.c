/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:48:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 10:07:55 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot(char *format, t_modifiers *mods)
{
	if (*format == '.')
		mods->dot = 1;
}

void	star(char *format, t_modifiers *mods)
{
	if (*format == '*')
		mods->star = 1;
}

void	minus(char *format, t_modifiers *mods)
{
	if (*format == '-')
		mods->minus = 1;
}

void	plus(char *format, t_modifiers *mods)
{
	if (*format == '+')
		mods->minus = 1;
}

void	zero(char *format, t_modifiers *mods)
{
	if (*format == '0')
		mods->zero = 1;
}

void	space(char *format, t_modifiers *mods)
{
	if (*format == ' ')
		mods->space = 1;
}

void	hashtag(char *format, t_modifiers *mods)
{
	if (*format == '#')
		mods->hash = 1;
}
