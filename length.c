/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:18:27 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/22 09:31:18 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_length(char *format, t_modifiers *modifiers)
{
	if (*format++ == 'l')
		modifiers->l = 1;
	if (*format == 'l')
		modifiers->l = 2;
}

void	h_length(char *format, t_modifiers *modifiers)
{
	if (*format++ == 'h')
		modifiers->h = 1;
	if (*format == 'h')
		modifiers->h = 2;
}
