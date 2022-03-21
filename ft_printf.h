/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:58:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/21 14:47:48 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define CONV "discoxfpu"
# define LEN "lh"
# define CAPITAL 32

typedef struct s_flags
{
	int		plus;
	int		minus;
	int		dot;
	int		hash;
	int		space;
	int		l;
	int		h;
}			t_flags;

typedef int				(*t_converse)(va_list args, char *format);
typedef void			(*t_length)(char *format, t_flags *flags);

int						c_converse(va_list args, char *format);
int						d_converse(va_list args, char *format);
int						s_converse(va_list args, char *format);
int						o_converse(va_list args, char *format);
int						x_converse(va_list args, char *format);
int						ft_printf(char *format, ...);
int						conversion(va_list args, char *format);
int						find_letter(char c, char *letters);
int						f_converse(va_list args, char *format);
int						p_converse(va_list args, char *format);
int						u_converse(va_list args, char *format);
void					l_flag(char *format, t_flags *flags);
void					h_flag(char *format, t_flags *flags);
//void					init_struct(t_flags *flags);

 static const t_length	g_length[5] = {
	 l_flag,
	 h_flag
 };

static const t_converse	g_specif[10] = {
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
