/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:58:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/24 12:12:58 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define CONV " discoxXfpu"
# define MODS ".-+0#* "
# define LEN "lhL"
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
	int			precision;
}				t_modifiers;

typedef int				(*t_converse)(va_list args, t_modifiers *mods);
typedef char			*(*t_mods)(va_list args, char *format, t_modifiers *mods);
typedef void			(*t_length)(char *format, t_modifiers *mods);
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

void					l_length(char *format, t_modifiers *mods);
void					h_length(char *format, t_modifiers *mods);
void					ld_length(char *format, t_modifiers *mods);

char					*check_modifiers(char *format, t_modifiers *mods, va_list args);

char					*dot(va_list args, char *format, t_modifiers *mods);
char					*star(va_list args, char *format, t_modifiers *mods);
char					*minus(va_list args, char *format, t_modifiers *mods);
char					*plus(va_list args, char *format, t_modifiers *mods);
char					*space(va_list args, char *format, t_modifiers *mods);
char					*hashtag(va_list args, char *format, t_modifiers *mods);
char					*zero(va_list args, char *format, t_modifiers *mods);
char					*cap_x(va_list args, char *format, t_modifiers *mods);

char					*type_cast(unsigned long long num, t_modifiers *mods, int base);
char					*type_cast_int(long long int num, t_modifiers *mods);
char					*type_cast_double(long double num, t_modifiers *mods);

char 					*treat_precision(char *string, t_modifiers *mods);

//char					*type_cast_double(double long num, t_modifiers *mods)


//int						ld_converse(va_list args, t_modifiers *mods);

//void					init_struct(t_modifiers *mods);

//  static const t_length	g_length[5] = {
// 	 l_length,
// 	 h_length
//  };

 static const t_mods	g_mods[15] = {
	 dot
	//  minus,
	//  plus,
	//  zero,
	//  hashtag,
	//  star,
	//  space,
 };

 static const t_length	g_length[3] = {
	l_length,
	h_length,
	ld_length
 };

//  static const t_treat	g_treat[3] = {
// 	treat_precision
//  };

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
