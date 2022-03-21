/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:06:29 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/21 14:50:08 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_letter(char c, char *letters)
{
	int	index;

	index = 0;
	while (letters[index++])
	{
		if (letters[index] == c)
			return (index);
	}
	return (0);
}

int	conversion(va_list args, char *format)
{
	int		char_count;
	t_flags	*flags;

	char_count = 0;
	flags = ft_memalloc(sizeof(t_flags));
	while (*format)
	{
		if (*format == '%' && format++)
		{
			g_length[find_letter(*format, LEN)](format, flags);
			format++;
			char_count += g_specif[find_letter(*format, CONV)](args, format);
		}	
		else if (*(format - 1) != '%')
			ft_putchar(*format);
		format++;
	}
	return (char_count);
}

int	ft_printf(char *format, ...)
{
	va_list	list;
	int		count;
	char	*temp;

	temp = ft_strdup(format);
	count = 0;
	if (!temp)
		return (-1);
	va_start(list, format);
	count += conversion (list, temp);
	va_end(list);
	free(temp);
	return (count);
}
