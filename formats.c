/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/23 14:21:08 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_converse(va_list args, t_modifiers *mods)
{
	char	*string;

	(void)mods;
	string = va_arg(args, char *);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	d_converse(va_list args, t_modifiers *mods)
{
	long long		num;
	char			*string;

	num = va_arg(args, long long );
	string = type_cast_int(num, mods);
	mods->h = 0;
	ft_putstr(string);
	return (ft_strlen(string));
}

int	c_converse(va_list args, t_modifiers *mods)
{
	int	c;
	(void)mods;
	c = va_arg(args, int );
	ft_putchar(c);
	return (1);
}

int	o_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char	*string;

	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 8);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	x_converse(va_list args, t_modifiers *mods)
{
	unsigned long long		num;
	char					*string;

	num = va_arg(args, unsigned long long int );
	string = type_cast(num, mods, 16);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	p_converse(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;

	num = va_arg(args, long long int );
	string = ft_strjoin("0x", ft_itoabase(num, 16, 1));
	ft_putstr(string);
	(void)mods;
	return (ft_strlen(string));
}

int	f_converse(va_list args, t_modifiers *mods)
{
	long double	num;
	char	*string;

	if (mods->ld == 1)
		num = va_arg(args, long double );
	else
		num = va_arg(args, double );
	string = ft_ftoa(num, 6);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	u_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char			*string;

	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 10);
	ft_putstr(string);
	return (ft_strlen(string));
}

