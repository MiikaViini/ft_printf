/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:31:30 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/21 14:46:46 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*init_struct(t_flags *flags)
{
	ft_memalloc(t_flags);
	flags->plus = 0;
	flags->minus = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->l = 0;
	flags->h = 0;
	return(flags);
}
