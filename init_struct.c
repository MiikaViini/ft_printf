/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:31:30 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/11 11:19:14 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_modifiers		*init_struct(t_modifiers *mods)
{
	mods->plus = 0;
	mods->minus = 0;
	mods->dot = 0;
	mods->hash = 0;
	mods->space = 0;
	mods->zero = 0;
	mods->star = 0;
	mods->l = 0;
	mods->h = 0;
	mods->ld = 0;
	mods->capital = 0;
	mods->precision = 0;
	return (mods);
}
