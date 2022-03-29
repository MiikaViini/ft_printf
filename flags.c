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

char	*dot(va_list args, char *format, t_modifiers *mods)
{
	char	*num;
	int		i;
	int		prec_int;

	i = 0;
	num = ft_strnew(21);
	prec_int = 0;
	if (format++ && mods->star == 1)
	{
		mods->precision = va_arg(args, int );
		return (format);
	}
	while (*format >= '0' && *format <= '9')
		num[i++] = *format++;
	mods->precision = ft_atoi(num);
	mods->dot = 1;
	return (format);
}

// char	*star(va_list args, char *format, t_modifiers *mods)
// {
// 	if (*format == '*')
// 		mods->star = 1;
// 	return (format);
// }

// char	*minus(va_list args, char *format, t_modifiers *mods)
// {
// 	if (*format == '-')
// 		mods->minus = 1;
// 	return (format);
// }

// char	*plus(va_list args, char *format, t_modifiers *mods)
// {
// 	if (*format == '+')
// 		mods->minus = 1;
// 	return (format);
// }

// char	*zero(va_list args, char *format, t_modifiers *mods)
// {
// 	if (*format == '0')
// 		mods->zero = 1;
// 	return (format);
// }

// char	*space(va_list args, char *format, t_modifiers *mods)
// {
// 	if (*format == ' ')
// 		mods->space = 1;
// 	return (format);
// }

// char	*hashtag(va_list args, char *format, t_modifiers *mods)
// {
// 	if (*format == '#')
// 		mods->hash = 1;
// 	return (format);
// }
