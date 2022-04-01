/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/01 21:46:43 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	unsigned long long joo = 922337203;
	//long  juu = 0;
	// char *joo = "jouo";
	//double jaa = 23.1;
	char *pok = "fiesta hattu";

	ft_printf("[%-20p]\n", joo);
	printf("[%-20p]\n", joo);
}
