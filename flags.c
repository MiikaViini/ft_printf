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

// int	precision(va_list args, char *format)
// {
// 	char	*precision;
// 	int		i;
// 	int		prec_int;

// 	i = 0;
// 	precision = ft_strnew(21);
// 	prec_int = 0;
// 	while (*format >= '0' && *format <= '9')
// 	{
// 		precision[i] = format[i];
// 		i++;
// 	}
// 	prec_int = ft_atoi(precision);
// 	return (prec_int);
// }

void	dot(char *format, t_modifiers *mods)
{
	if (*format++ == '.')
		mods->dot = 1;
}

void	star(char *format, t_modifiers *mods)
{
	if (*format++ == '*')
		mods->star = 1;
}

void	minus(char *format, t_modifiers *mods)
{
	if (*format++ == '-')
		mods->minus = 1;
}

void	plus(char *format, t_modifiers *mods)
{
	if (*format++ == '+')
		mods->minus = 1;
}

void	zero(char *format, t_modifiers *mods)
{
	if (*format++ == '0')
		mods->minus = 1;
}

void	space(char *format, t_modifiers *mods)
{
	if (*format++ == ' ')
		mods->minus = 1;
}

void	hashtag(char *format, t_modifiers *mods)
{
	if (*format++ == ' ')
		mods->minus = 1;
}
