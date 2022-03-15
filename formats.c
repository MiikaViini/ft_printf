/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/15 19:14:17 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	o_converse(va_list args)
{
	int		num;
	char	*string;

	num = va_arg(args, int );
	//printf("%dwhat", num);
	string = ft_itoabase(num, 8, 1);
	ft_putstr(string);
	//ft_putnbr(num);
	return (ft_strlen(string));
}

int	x_converse(va_list args)
{
	int		num;
	char	*string;

	num = va_arg(args, int );
	//printf("%dwhat", num);
	string = ft_itoabase(num, 16, 1);
	ft_putstr(string);
	//ft_putnbr(num);
	return (ft_strlen(string));
}
