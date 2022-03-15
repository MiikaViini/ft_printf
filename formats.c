/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/15 23:19:26 by mviinika         ###   ########.fr       */
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
	string = ft_itoabase(num, 8, 1);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	x_converse(va_list args)
{
	int		num;
	char	*string;

	num = va_arg(args, int );
	string = ft_itoabase(num, 16, 1);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	p_converse(va_list args)
{
	int		num;
	char	*string;

	num = va_arg(args, int );
	string = ft_strjoin("0x", ft_itoabase(ft_abs(num), 16, 1));
	ft_putstr(string);
	return (ft_strlen(string));
}

int	f_converse(va_list args)
{
	double	num;
	char	*string;

	num = va_arg(args, double );
	string = ft_ftoa(num, 6);
	ft_putstr(string);
	return (ft_strlen(string));
}
