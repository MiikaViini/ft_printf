/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:06:29 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/12 20:58:26 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

int	s_converse(va_list args)
{
	char	*string;

	string = va_arg(args, char *);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	d_converse(va_list args)
{
	int	num;

	num = va_arg(args, int );
	ft_putnbr(num);
	return (ft_intlen(num));
}

int	c_converse(va_list args)
{
	int	c;

	c = va_arg(args, int );
	ft_putchar(c);
	return (1);
}

typedef int	t_converse(va_list args);

t_converse *dispatcher[8] = {
	d_converse,
	d_converse,
	s_converse,
	c_converse
};


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
			char_count += dispatcher[find_letter(*format, letter)](args);
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

int	main(void)
{
	char strng[] = "Jees";
	int	num = 100;

	ft_printf("mita%s%s%d%i%c%o%d\n", strng, strng, num, num, 'c');
	printf("mita%s%s%d%i%c%o%d\n", strng, strng, num, num, 'c');
	//system("leaks a.out");
	return (0);
}
