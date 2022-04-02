/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:45:22 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/23 22:51:20 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_num(va_list args, char *format, t_modifiers *mods)
{
	char	*num;
	int		i;
	int		prec_int;

	i = 0;
	num = ft_strnew(21);
	prec_int = 0;
	while (*format >= '0' && *format <= '9')
		num[i++] = *format++;
	mods->precision = ft_atoi(num);
	return (format);
}
