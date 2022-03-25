/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/25 17:39:28 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	//int joo = 123;
	long double juh = -0.0;

	ft_printf("%.2Lf\n", juh);
	printf("%.20Lf\n", juh);
}
