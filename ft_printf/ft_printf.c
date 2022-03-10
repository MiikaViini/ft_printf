/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:06:29 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/10 14:34:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef int	t_functions(va_list args, char *format);

int	s_converse(va_list args, char *format)
{
	char	*string;

	string = va_arg(args, char *);

	ft_putstr(string);
	format++;
	return (ft_strlen(string));
}

int	d_converse(va_list args, char *format)
{
	int num;

	num = va_arg(args, int );

	ft_putnbr(num);
	format++;
	return (ft_intlen(num));
}

int	ft_printf(char *format, ...)
{
	va_list	list;
	int		count;

	va_start(list, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				s_converse(list, format++);
			if (*format == 'd')
				d_converse(list, format++);
		}
		ft_putchar(*format);
		format++;
	}
	return (0);
}

int	main(void)
{
	char strng[] = "Jees";
	int	num = 6;
	
	ft_printf("fgfg%shf%sg%d", strng, strng, num);
}