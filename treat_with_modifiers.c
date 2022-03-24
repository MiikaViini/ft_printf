/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_with_modifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:04:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/24 11:30:59 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *treat_precision(char *string, t_modifiers *mods)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	res = ft_strnew(mods->precision);
	len = ft_strlen(string);
	while (len < mods->precision)
	{
		res[i++] = '0';
		mods->precision--;
	}
	return (ft_strjoin(res, string));
}