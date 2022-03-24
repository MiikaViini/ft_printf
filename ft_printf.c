/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:06:29 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/24 11:33:19 by mviinika         ###   ########.fr       */
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

char	*check_modifiers(char *format, t_modifiers *mods, va_list args)
{
	int	i;

	i = 0;
	while (!find_letter(*format, CONV))
	{
		format = g_mods[find_letter(*format, MODS)](args, format, mods);
		g_length[find_letter(*format, LEN)](format, mods);
	}
	//exit(1);
	if (*format == 'x')
		mods->cap_x = 1;
	return (format);
}

int	conversion(va_list args, char *format)
{
	int			ch_count;
	t_modifiers	*modifiers;

	ch_count = 0;
	modifiers = ft_memalloc(sizeof(t_modifiers));
	while (*format)
	{
		while (*format == '%')
		{
			format++;
			format = check_modifiers(format, modifiers, args);
			ch_count += g_specif[find_letter(*format++, CONV)](args, modifiers);
		}
		ft_putchar(*format++);
	}
	free(modifiers);
	return (ch_count);
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
	//system("leaks a.out");
	return (count);
}
