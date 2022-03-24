/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:29:41 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/24 13:56:57 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_converse(va_list args, t_modifiers *mods)
{
	char	*string;
	int		count;

	(void)mods;
	string = va_arg(args, char *);
	//string = treat_precision(string, mods);
	
	ft_putstr(ft_strndup(string, mods->precision));
	count = ft_strlen(string);
	//free(string);
	return (count);
}

int	d_converse(va_list args, t_modifiers *mods)
{
	long long		num;
	int				count;
	char			*string;

	num = va_arg(args, long long );
	string = type_cast_int(num, mods);
	count = ft_strlen(string);
	string = treat_precision(string, mods);
	ft_putstr(string);
	free(string);
	return (count);
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
	char				*string;
	int					count;

	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 8);
	count = ft_strlen(string);
	ft_putstr(string);
	free(string);
	return (count);
}

int	x_converse(va_list args, t_modifiers *mods)
{
	unsigned long long		num;
	char					*string;
	int						count;

	num = va_arg(args, unsigned long long int );
	string = type_cast(num, mods, 16);
	count = ft_strlen(string);
	ft_putstr(string);
	free(string);
	return (count);
}

int	p_converse(va_list args, t_modifiers *mods)
{
	long long int	num;
	char			*string;
	int				count;

	num = va_arg(args, long long int );
	string = ft_strjoin("0x", ft_itoabase(num, 16, 1));
	count = ft_strlen(string);
	ft_putstr(string);
	free(string);
	(void)mods;
	return (count);
}

int	f_converse(va_list args, t_modifiers *mods)
{
	long double		num;
	char			*string;
	int				count;

	if (mods->ld == 1)
	num = va_arg(args, long double );
	else
		num = va_arg(args, double );
	string = ft_ftoa(num, mods->precision);
	//string = type_cast_double(num, mods);
	count = ft_strlen(string);
	ft_putstr(string);
	free(string);
	return (count);
}

int	u_converse(va_list args, t_modifiers *mods)
{
	unsigned long long	num;
	char				*string;
	int					count;

	num = va_arg(args, unsigned long long );
	string = type_cast(num, mods, 10);
	count = ft_strlen(string);
	ft_putstr(string);
	free(string);
	return (count);
}
