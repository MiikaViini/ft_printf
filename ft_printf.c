/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:06:29 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 11:57:09 by mviinika         ###   ########.fr       */
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

char	*check_modifiers(char *format, t_modifiers *mods)
{
	int	i;

	i = 0;
	while (!ft_strrchr(format, CONV[i++]) && *format)
	{
		g_mods[find_letter(*format, MODS)](format, mods);
		//format++;
	}
	return (format);
}

int	conversion(va_list args, char *format)
{
	int			char_count;
	t_modifiers	*modifiers;

	char_count = 0;
	modifiers = ft_memalloc(sizeof(t_modifiers));
	while (*format)
	{
		if (*format == '%' && format++)
		{
			//g_mods[find_letter(*format, MODS)](format, modifiers);
			format = check_modifiers(format, modifiers);
			
			//g_flags[find_letter(*format, LEN)](format, modifiers);
			char_count += g_specif[find_letter(*format, CONV)](args, modifiers);
		}
		else if (*(format - 1) != '%')
			ft_putchar(*format);
		format++;
	}
	free(modifiers);
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
