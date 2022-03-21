/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/21 14:43:24 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_flag(char *format, t_flags *flags)
{
	if (*format++ == 'l')
		flags->l = 1;
	if (*format == 'l')
		flags->l = 2;
}

void	h_flag(char *format, t_flags *flags)
{
	if (*format++ == 'h')
		flags->h = 1;
	if (*format == 'h')
		flags->h = 2;
}
