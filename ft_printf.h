/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:58:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/21 09:41:48 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define CONV "discoxfpu"
# define LENGTH "lh"
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
typedef void			*(*t_length)(long long int value);

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
int						u_converse(va_list args);
long long int			l_flag(long long int value);
void					*ll_flag(void *value);
void					*h_flag(void *value);
// void					*hh_flag(void *value);

//  static const t_flags 	g_length[5] = {
// 	 l_flag,.
// 	 ll_flag,
// 	 h_flag,
// 	 hh_flag
//  };

static const t_converse	g_dispatcher[10] = {
	d_converse,
	d_converse,
	s_converse,
	c_converse,
	o_converse,
	x_converse,
	f_converse,
	p_converse,
	u_converse
};

#endif
