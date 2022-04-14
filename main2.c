/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:08:03 by mviinika          #+#    #+#             */
/*   Updated: 2022/04/14 13:31:17 by mviinika         ###   ########.fr       */
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
	int i = 42;
	int a = 0;
	static unsigned int uin = 238;
	static char c = 'G';
	static char *str = "Hello World";

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

	// i = ft_printf("[%-*s]\n", -32, "abc");
	// a =	printf("[%-*s]\n", -32, "abc");

	// i = ft_printf("[%*s]\n", -32, "abc");
	// a =	printf("[%*s]\n", -32, "abc");

	// i = ft_printf("[%.f]\n", 1.5);
	// a =	printf("[%.f]\n", 1.5);
	
	

	

	// i = ft_printf("[%.f]\n", 9.50000);
	// a =	printf("[%.f]\n", 9.50000);

	// i = ft_printf("[%.15f]\n", 1.00002);
	// a =	printf("[%.15f]\n", 1.00002);


	// i = ft_printf("[%.15f]\n", 1.56423335);
	// a =	printf("[%.15f]\n", 1.56423335);


	// i = ft_printf("[%.15f]\n", 1.5643339);
	// a =	printf("[%.15f]\n", 1.5643339);

	i = ft_printf("[%5.0d]\n", -392082);
	a =	printf("[%5.0d]\n", -392082);


	// i = ft_printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);
	// a =	printf("[%s  %x    %X %c %u  %p  ]\n", str, uin, uin, c,uin, &i);

	// i = ft_printf("[%.5x]\n", 21);
	// a =	printf("[%.5x]\n", 21);
	//printf("%d", a);
	return (0);
}


