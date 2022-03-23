/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:58:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/23 11:26:27 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define CONV " discoxXfpu"
# define MODS "-+.0#* lhL"
# define CAPITAL 32

typedef struct s_modifiers
{
	int			plus;
	int			minus;
	int			dot;
	int			hash;
	int			space;
	int			zero;
	int			star;
	int			l;
	int			h;
	int			ld;
	int			cap_x;
}				t_modifiers;

typedef int				(*t_converse)(va_list args, t_modifiers *mods);
typedef void			(*t_mods)(char *format, t_modifiers *mods);

int						ft_printf(char *format, ...);
int						conversion(va_list args, char *format);
int						find_letter(char c, char *letters);
int						f_converse(va_list args, t_modifiers *mods);
int						p_converse(va_list args, t_modifiers *mods);
int						u_converse(va_list args, t_modifiers *mods);
int						c_converse(va_list args, t_modifiers *mods);
int						d_converse(va_list args, t_modifiers *mods);
int						s_converse(va_list args, t_modifiers *mods);
int						o_converse(va_list args, t_modifiers *mods);
int						x_converse(va_list args, t_modifiers *mods);

void					l_length(char *format, t_modifiers *mods);
void					h_length(char *format, t_modifiers *mods);

char					*check_modifiers(char *format, t_modifiers *mods);

void					dot(char *format, t_modifiers *mods);
void					star(char *format, t_modifiers *mods);
void					minus(char *format, t_modifiers *mods);
void					plus(char *format, t_modifiers *mods);
void					space(char *format, t_modifiers *mods);
void					hashtag(char *format, t_modifiers *mods);
void					zero(char *format, t_modifiers *mods);
void					cap_x(char *format, t_modifiers *mods);
char					*type_cast(unsigned long long num, t_modifiers *mods, int base);
char					*type_cast_int(long long int num, t_modifiers *mods);
char					*type_cast_double(long double num, t_modifiers *mods);
void					ld_length(char *format, t_modifiers *modifiers);


//int						ld_converse(va_list args, t_modifiers *mods);

//void					init_struct(t_modifiers *mods);

//  static const t_length	g_length[5] = {
// 	 l_length,
// 	 h_length
//  };

 static const t_mods	g_mods[15] = {
	 minus,
	 plus,
	 dot,
	 zero,
	 hashtag,
	 star,
	 space,
	 l_length,
	 h_length,
	 ld_length
 };

static const t_converse	g_specif[15] = {
	d_converse,
	d_converse,
	d_converse,
	s_converse,
	c_converse,
	o_converse,
	x_converse,
	x_converse,
	f_converse,
	p_converse,
	u_converse
	// ld_converse
};

#endif
