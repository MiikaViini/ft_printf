/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:06:29 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/14 13:26:32 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_letter(char c, char *letters)
{
	int	index;

	index = 0;
	while (letters[index] && letters[index] != c)
		index++;
	return (index);
}

int	conversion(va_list args, char *format)
{
	int		char_count;
	char	*letter;

	letter = ft_strdup("dis");
	char_count = 0;
	while (*format)
	{
		if (*format == '%' && format++)
			char_count += g_dispatcher[find_letter(*format, letter)](args);
		else if (*(format - 1) != '%')
			ft_putchar(*format);
		format++;
	}
	free(letter);
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
	free(temp);
	return (count);
}
