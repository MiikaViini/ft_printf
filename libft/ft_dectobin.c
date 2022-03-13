/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:48:10 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/01 09:52:34 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dectobin(int dec)
{
	int		res;
	int		bin[16];
	size_t	i;

	res = 0;
	i = 0;
	while (dec > 0)
	{
		bin[i] = dec % 2;
		dec /= 2;
		i++;
	}
	while (i--)
	{
		ft_putnbr(bin[i]);
	}
	ft_putchar('\n');
}
