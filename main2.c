/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:34:02 by m3iinika          #+#    #+#             */
/*   Updated: 2022/04/13 07:56:53 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main()
{
	long long joo = 922337203685477580;
	//long  juu = 0;
	// char *joo = "jouo";
	//double jaa = 23.145;
	//char per = '%';
	int i = 0;
	int a = 0;

	// i = ft_printf("[%5d]\n", -12);
	// a =	printf("[%5d]\n", -12);

	// i = ft_printf("[%-5d]\n", -12);
	// a =	printf("[%-5d]\n", -12);

	// i = ft_printf("[%-05d]\n", -12);
	// a =	printf("[%-05d]\n", -12);

	// i = ft_printf("[%+10.5d]\n", -12);
	// a =	printf("[%+10.5d]\n", -12);

	// i = ft_printf("[%+10.5d]\n", -12);
	// a =	printf("[%+10.5d]\n", -12);

	// i = ft_printf("[%+10.5d]\n", 4242);
	// a =	printf("[%+10.5d]\n", 4242);

	//  i = ft_printf("MY [%.5d]\n", 42);
	//  a =	printf("OG [%.5d]\n", 42);

	// i = ft_printf("[%05d]\n", 42);
	// a =	printf("[%05d]\n", 42);

	// i = ft_printf("[%5d]\n", -42);
	// a =	printf("[%5d]\n", -42);

	// i = ft_printf("MY [%05d]\n", 42);
	// a =	printf("OG [%05d]\n", 42);

	// i = ft_printf("[%03.2d]\n", -1);
	// a =	printf("[%03.2d]\n", -1);

	i = ft_printf("[%04d]\n", -5352);
	a =	printf("[%04d]\n", -5325);

	i = ft_printf("[%04d]\n", -532);
	a =	printf("[%04d]\n", -535);

	// i = ft_printf("[%.5x]\n", 21);
	// a =	printf("[%.5x]\n", 21);
	//printf("%d", a);
	return (0);
}


