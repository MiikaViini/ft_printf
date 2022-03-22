/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 11:51:54 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_converse(va_list args, t_modifiers *mods)
{
	char	*string;
	printf("%d", mods->h);
	string = va_arg(args, char *);
	ft_putstr(string);
	return (ft_strlen(string));
}

int	d_converse(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;

	num = va_arg(args, long long int );
	string = ft_itoabase(cast_long(num, mods), 10, 0);
	//mods->h = 0;
	ft_putstr(string);
	return (1);
}

int	c_converse(va_list args, t_modifiers *mods)
{
	int	c;
	printf("%d", mods->h);
	c = va_arg(args, int );
	ft_putchar(c);
	return (1);
}

int	o_converse(va_list args, t_modifiers *mods)
{
	int		num;
	char	*string;

	num = va_arg(args, int );
	string = ft_itoabase(num, 8, 1);
	ft_putstr(string);
	printf("%d", mods->h);
	return (ft_strlen(string));
}

int	x_converse(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;

	num = va_arg(args, long long int );
	string = ft_itoabase(num, 16, 1);
	ft_putstr(string);
	mods->h = 0;
	return (ft_strlen(string));
}

int	p_converse(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;

	num = va_arg(args, long long int );
	string = ft_strjoin("0x", ft_itoabase(num, 16, 1));
	ft_putstr(string);
	printf("%d", mods->h);
	return (ft_strlen(string));
}

int	f_converse(va_list args, t_modifiers *mods)
{
	double	num;
	char	*string;

	num = va_arg(args, double );
	string = ft_ftoa(num, 2);
	ft_putstr(string);
	printf("%d", mods->h);
	return (ft_strlen(string));
}

int	u_converse(va_list args, t_modifiers *mods)
{
	unsigned int	num;
	char			*string;

	num = va_arg(args, unsigned int);
	string = ft_utoa(num);
	ft_putstr(string);
	printf("%d", mods->h);
	return (ft_strlen(string));
}
