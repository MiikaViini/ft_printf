/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:58:49 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/14 13:36:46 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef int					(*t_converse)(va_list args);

int		c_converse(va_list args);
int		d_converse(va_list args);
int		s_converse(va_list args);
int		ft_printf(char *format, ...);
int		conversion(va_list args, char *format);
int		find_letter(char c, char *letters);

static const t_converse 	g_dispatcher[8] = {
	d_converse,
	d_converse,
	s_converse,
	c_converse
};

#endif