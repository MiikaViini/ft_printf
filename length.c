/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/21 15:30:48 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_length(char *format, t_flags *flags)
{
	if (*format++ == 'l')
		flags->l = 1;
	if (*format == 'l')
		flags->l = 2;
}

void	h_length(char *format, t_flags *flags)
{
	if (*format++ == 'h')
		flags->h = 1;
	if (*format == 'h')
		flags->h = 2;
}

