/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:48:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/17 10:31:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision(va_list args, char *format)
{
	char	*precision;
	int		i;
	int		prec_int;

	i = 0;
	precision = ft_strnew(21);
	prec_int = 0;
	while (*format >= '0' && *format <= '9')
	{
		precision[i] = format[i];
		i++;
	}
	prec_int = ft_atoi(precision);
	
}