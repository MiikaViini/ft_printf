/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:58:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/03 17:34:35 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define CONV "discoxXfpu%"
# define MODS "* #-.+lhL"
//
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
	int			width;
	int			l;
	int			h;
	int			ld;
	int			cap_x;
	int			precision;
}				t_modifiers;

typedef int			(*t_converse)(va_list args, t_modifiers *mods);
typedef char		*(*t_mods)(va_list args, char *format, t_modifiers *mods);
//typedef char			*(*t_length)(char *format, t_modifiers *mods);
// typedef char			*(*t_treat)(char *format, t_modifiers *mods);



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
int 					per_converse(va_list args, t_modifiers *mods);

char					*l_length(va_list args, char *format, t_modifiers *mods);
char					*h_length(va_list args, char *format, t_modifiers *mods);
char					*ld_length(va_list args, char *format, t_modifiers *mods);

char					*check_modifiers(char *format, t_modifiers *mods, va_list args);

char					*dot(va_list args, char *format, t_modifiers *mods);
char					*star(va_list args, char *format, t_modifiers *mods);
char					*minus(va_list args, char *format, t_modifiers *mods);
char					*plus(va_list args, char *format, t_modifiers *mods);
char					*space(va_list args, char *format, t_modifiers *mods);
char					*hashtag(va_list args, char *format, t_modifiers *mods);
char					*zero(va_list args, char *format, t_modifiers *mods);
char					*cap_x(va_list args, char *format, t_modifiers *mods);
char					*width(va_list args, char *format, t_modifiers *mods);

char					*type_cast(unsigned long long num, t_modifiers *mods, int base);
char					*type_cast_int(long long int num, t_modifiers *mods);
char					*type_cast_double(long double num, t_modifiers *mods);

char					*treat_precision(char *string, t_modifiers *mods, int length);
char					*treat_width(char *string, t_modifiers *mods, int length, int num);
char					*check_infinity(double num);
char					*treat_w_mods(char *str, t_modifiers *mods, int count, int num);

t_modifiers				*init_struct(t_modifiers *mods);
char					*check_edges(t_modifiers *mods, char *format, int num);

char					*treat_zerox(char *string, t_modifiers *mods, int num);
char					*do_nothing(va_list args, char *format, t_modifiers *mods);
int						do_nothing_conv(va_list args, t_modifiers *mods);
static const t_mods	g_mods[15] = {
	star,
	space,
	hashtag,
	minus,
	dot,
	plus,
	l_length,
	h_length,
	ld_length,
	do_nothing
	//  zero,
	//  star,
	//  space,
};

static const t_converse	g_specif[15] = {
	d_converse,
	d_converse,
	s_converse,
	c_converse,
	o_converse,
	x_converse,
	x_converse,
	f_converse,
	p_converse,
	u_converse,
	per_converse,
	do_nothing_conv
};

#endif


//char					*type_cast_double(double long num, t_modifiers *mods)

//int						ld_converse(va_list args, t_modifiers *mods);

//void					init_struct(t_modifiers *mods);

//  static const t_length	g_length[5] = {
// 	 l_length,
// 	 h_length
//  };
