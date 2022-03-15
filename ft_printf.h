/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:58:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/15 22:48:38 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define CONV "discoxfp"
# define CAPITAL 32

typedef struct s_flags
{
	int		plus;
	int		minus;
	int		dot;
	int		hash;
	int		space;
}			t_flags;

typedef int				(*t_converse)(va_list args);

int						c_converse(va_list args);
int						d_converse(va_list args);
int						s_converse(va_list args);
int						o_converse(va_list args);
int						x_converse(va_list args);
int						ft_printf(char *format, ...);
int						conversion(va_list args, char *format);
int						find_letter(char c, char *letters);
int						f_converse(va_list args);
int						p_converse(va_list args);

static const t_converse	g_dispatcher[8] = {
	d_converse,
	d_converse,
	s_converse,
	c_converse,
	o_converse,
	x_converse,
	f_converse,
	p_converse
};

#endif
